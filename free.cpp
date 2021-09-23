#include <stdlib.h>

void FreeMemory(char* lineptrs[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++){
        free(lineptrs[i]);
    }
}
