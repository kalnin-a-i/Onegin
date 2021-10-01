#include "stdio.h"
#include "line.h"

//-------------------------------------------
/** @file */
//! Print strings to the screen according to their order in an array of pointers
//! @param[in] lineptrs array of pointers
//! @param[in] nlines number of strings
//! @param[in] out_ind the way how to print
//! @param[in] filepath path to file there to print
//------------------------------------------------
void WriteText(line *lineptrs[], int nlines, int out_ind, char *filepath)
{
    int i;

    if (out_ind >= 2 )
    {
        FILE *file = fopen(filepath, "w");

        for (i = 0; i < nlines; i++)
        {
            fprintf(file, "%s \n", lineptrs[i]->str);
        }
        fclose(file);
        return;
    }

    for (i = 0; i < nlines; i++)
    {
        printf("%s \n", lineptrs[i]->str);
    }
}

