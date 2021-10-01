#include <stdlib.h>
#include "line.h"

//----------------------------------------------
/** @file */
//! Frees memory allocated during program execution
//! @param[in] lineptrs an array of pointers to which memory is allocated
//! @param[in] nlines number of pointers in lineptrs
//----------------------------------------------------------------

void FreeMemory(line* lineptrs[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++){
        free(lineptrs[i]->str);
        free(lineptrs[i]);
    }
}
