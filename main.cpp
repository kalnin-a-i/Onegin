#include <stdio.h>
#include "line.h"

//----------------------------------------------
/** @file */
//---------------------------------------------

int GetText(line *lineptrs[], int maxlines, FILE *file);
void qSort(void *v[], int left, int right, int (*comp)(void *, void *));
void WriteText(line *lineptrs[], int nlines);
void FreeMemory(line* lineptrs[], int nlines);
int RevStrcmp(line* line1, line* line2);
int MyStrcmp(line *line1, line *line2);

#define MAXLINES 5000
line *lineptrs[MAXLINES];

int main() {

    FILE* file;
    file = fopen("/home/alexey/CLionProjects/Onegin_2/Onegin", "r");

    int nlines = GetText(lineptrs, MAXLINES, file);

    if (nlines >= 0)
    {
        printf("Alphabet order:\n\n");
        qSort((void**) lineptrs, 0, nlines - 1, (int (*)(void*, void*))(MyStrcmp));
        WriteText(lineptrs, nlines);

        printf("\n\nReverse alphabet order:\n\n");
        qSort((void **) lineptrs, 0, nlines-1, (int (*)(void*, void*))(RevStrcmp));
        WriteText(lineptrs, nlines);

        FreeMemory(lineptrs, nlines);
        fclose(file);
        return 0;
    } else
    {
        printf("error: input too big to sort\n");
        fclose(file);
        return 1;
    }
}
