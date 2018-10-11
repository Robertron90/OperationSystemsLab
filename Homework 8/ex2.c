#include <stdlib.h>

#include <stdio.h>

#include <time.h>



int main(){

  
	for(int i=0; i < 10; i++){
    
		void* byte1 = malloc(sizeof(char)<<20);
    
		byte1 = memset(byte1, 0, sizeof(char)<<20);
    
		sleep(1);
  
	}



}
