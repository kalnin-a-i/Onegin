#include "stdio.h"
#include "line.h"

//-------------------------------------------
/** @file */
//! Print strings to the screen according to their order in an array of pointers
//! @param[in] lineptrs array of pointers
//! @param[in] nlines number of strings
//------------------------------------------------
void WriteText(line *lineptrs[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s \n", lineptrs[i]->str);
    }
}

