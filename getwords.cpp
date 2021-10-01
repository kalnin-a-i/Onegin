#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "line.h"

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

int GetText(line *lineptrs[], int maxlines, FILE *file)
{
    char str[MAXLEN];
    int nlines, len;
    line *p{};

    nlines = 0;
    while ((len = GetLine(str, file, MAXLEN)) > 0)
    {
        p = (line*)calloc(1, sizeof(char));
        p->str = (char*)calloc(len, sizeof(char));
        if(nlines > MAXLEN and p == NULL and p->str == NULL)
        {
            return -1;
        }
        else
        {
            strcpy(p->str, str);
            p->len = len;
            lineptrs[nlines++] = p;
        }
    }
    return nlines;
}