#include <stdio.h>


void writewords(char* lineptrs[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s \n", lineptrs[i]);
    }
}

