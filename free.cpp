#include <stdlib.h>

void freememory(char* lineptrs[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++){
        free(lineptrs[i]);
    }
}
