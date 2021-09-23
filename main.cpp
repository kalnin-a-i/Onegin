#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetText(char* lineptrs[], int maxlines, FILE* poem);
void qSort(void *v[], int left, int right, int (*comp)(void *, void *));
void WriteText(char* lineptrs[], int nlines);
void FreeMemory(char* lineptrs[], int nlines);
int RevStrcmp(char* str1, char* str2);

#define MAXLINES 5000
char *lineptrs[MAXLINES];

int main() {

    FILE* file;
    file = fopen("/home/alexey/CLionProjects/Onegin_2/Onegin", "r");

    int nlines = GetText(lineptrs, MAXLINES, file);

    if (nlines >= 0) {
        qSort((void **) lineptrs, 0, nlines-1, (int (*)(void*, void*))(RevStrcmp));
        WriteText(lineptrs, nlines);
        FreeMemory(lineptrs, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }


}
