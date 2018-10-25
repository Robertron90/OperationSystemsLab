#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int ifinder(int *array, int size, int e)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == e)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int inodes[10];
    char *files[10];
    int results[10];

    DIR *dirp = opendir("tmp");
    struct dirent *pf;
    int i = 0;
    int count = 0;
    while ((pf = readdir(dirp)) != NULL)
    {
        int index = ifinder(inodes, i, pf->d_ino);
        if (index >= 0)
        {
            if (ifinder(results, count, index) < 0)
            {
                results[count] = index;
                count++;
            }
            results[count] = i;
            count++;
        }

        files[i] = pf->d_name;
        inodes[i] = pf->d_ino;
        i++;
    }

    closedir(dirp);

    for (int j = 0; j < count; j++)
    {
        printf("%s\n", files[results[j]]);
    }
}