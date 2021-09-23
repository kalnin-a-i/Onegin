#include <stdlib.h>

//----------------------------------------------
/** @file */
//! Frees memory allocated during program execution
//! @param[in] lineptrs an array of pointers to which memory is allocated
//! @param[in] nlines number of pointers in lineptrs
//----------------------------------------------------------------

void FreeMemory(char* lineptrs[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++){
        free(lineptrs[i]);
    }
}
