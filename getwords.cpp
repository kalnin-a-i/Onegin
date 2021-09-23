#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000
int GetLine(char *line, FILE *file, int maxlen);


//---------------------------------------------------------------------------------------------------
/** @file */
//! reading lines from input file and write their adresses to array of ponters
//! @param[in] lineptrs array of pointer to lines
//! @param[in] maxlines maximal number of lines
//! @return number of lines
//! @note returns -1 if len of length of line > then maximal length or failed to allocate memory
//----------------------------------------------------------------------------------------------------

int GetText(char *lineptrs[], int maxlines, FILE *poem)
{
    char *p, line[MAXLEN];
    int nlines, len;

    nlines = 0;
    while ((len = GetLine(line, poem, MAXLEN)) > 0)
    {
        p = (char*)calloc(len, sizeof(char));
        if(nlines > MAXLEN and p == NULL)
        {
            return -1;
        }
        else
        {
            strcpy(p, line);
            lineptrs[nlines++] = p;
        }
    }
    return nlines;
}


