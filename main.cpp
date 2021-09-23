#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//----------------------------------------------
/** @file */
//---------------------------------------------

int GetText(char* lineptrs[], int maxlines, FILE* poem);
void qSort(void *v[], int left, int right, int (*comp)(void *, void *));
void WriteText(char* lineptrs[], int nlines);
void FreeMemory(char* lineptrs[], int nlines);
int RevStrcmp(char* str1, char* str2);
void TestRev();

#define MAXLINES 5000
char *lineptrs[MAXLINES];

int main() {

    //TestRev();

    FILE* file;
    file = fopen("/home/alexey/CLionProjects/Onegin_2/Onegin", "r");

    int nlines = GetText(lineptrs, MAXLINES, file);

    if (nlines >= 0)
    {
        printf("\n\nAlphabet order\n\n");
        qSort((void**) lineptrs, 0, nlines - 1, (int (*)(void*, void*))(strcmp));
        WriteText(lineptrs, nlines);

        printf("\n\nReverse alphabet order\n\n");
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
