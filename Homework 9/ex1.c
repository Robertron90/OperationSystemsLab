#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void AgeIncrease (int frames);
int OldestIndex (int frames);

struct PageTable {
	int frame_number;
	bool valid;
}*PageTable;

struct FrameTable {
	int page_number;
	int age;
}*FrameTable;

int main (void){
	printf("Number of pages:\n");
	int pages;
	scanf("%d", &pages);
	
	printf("Number of frames:\n");
	int frames;
	scanf("%d", &frames);
	
	PageTable=malloc(sizeof(PageTable)*pages);
	FrameTable=malloc(sizeof(FrameTable)*frames);
	
	int i;
	for (i=0;i<pages; i++){
		PageTable[i].valid=false;
	}
	
	for (i=0;i<frames;i++){
		FrameTable[i].age=0;
	}
	
	FILE *fp=fopen("file.txt", "r");
	
	int request;
	int frame_table_counter=0;
	int page_fault_counter=0;
	int request_counter=0;
	int memory_ref_counter=0;
	//add frame size to page faults later
	while (!feof(fp)){
		fscanf(fp, "%d", &request);
		request_counter++;
		if (PageTable[request].valid==false){
			FrameTable[frame_table_counter].page_number=request;
			PageTable[request].valid=true;
			PageTable[request].frame_number=frame_table_counter;
			frame_table_counter++;
			page_fault_counter++;
			memory_ref_counter++;
		}	
		
		if (request_counter==1000){
			FILE *fp=fopen("data.txt", "a");
			fprintf (fp, "%d\n", memory_ref_counter);
			memory_ref_counter=0;
			request_counter=0;
			fclose(fp);
		}
		if (frame_table_counter==frames){
			break;
		}
	}
	
	
	while (!feof(fp)){
		fscanf(fp, "%d", &request);
		request_counter++;
		AgeIncrease(frames);
		if (PageTable[request].valid==false){
			int oldest_page=OldestIndex(frames);
			PageTable[FrameTable[oldest_page].page_number].valid=false;
			FrameTable[oldest_page].page_number=request;
			FrameTable[oldest_page].age=0;
			PageTable[request].frame_number=oldest_page;
			PageTable[request].valid=true;
			page_fault_counter++;
			memory_ref_counter++;
		}
		
		if (request_counter==1000){
			FILE *fp=fopen("input.txt", "a");
			fprintf (fp, "%d\n", memory_ref_counter);
			memory_ref_counter=0;
			request_counter=0;
			fclose(fp);
		}
	}
	
	printf("References: %d\nFaults: %d\nRatio: %f\n", Frametable.age, page_fault_counter, (double)(Frametable.age - page_fault_counter) / page_fault_counter);

	fclose(fp);
	free(PageTable);
	free(FrameTable);
	
	return 0;
}

void AgeIncrease (int frames){
	int i;
	for (i=0;i<frames;i++){
		FrameTable[i].age++;
	}
}

int OldestIndex (int frames){
	int oldest=-1;
	int i;
	int index;
	for (i=0;i<frames;i++){
		if (oldest<FrameTable[i].age){
			oldest=FrameTable[i].age;
			index=i;
		}
	}
	return index;
}