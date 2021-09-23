#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gettext(char* lineptrs[], int maxlines, FILE* poem);
void qsort(char* lineptrs[], int left, int rigth);
void writewords(char* lineptrs[], int nlines);
void freememory(char* lineptrs[], int nlines);

#define MAXLINES 5000
char *lineptrs[MAXLINES];

int main() {

    FILE* file;
    file = fopen("/home/alexey/CLionProjects/Onegin_2/Onegin", "r");

    int nlines = gettext(lineptrs, MAXLINES, file);

    if (nlines >= 0) {
        qsort(lineptrs, 0, nlines-1);
        writewords(lineptrs, nlines);
        freememory(lineptrs, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }


}
