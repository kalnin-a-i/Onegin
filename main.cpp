#include <stdio.h>
#include "line.h"

//----------------------------------------------
/** @file */
//---------------------------------------------

int GetText(line *lineptrs[], int maxlines, FILE *file);
void qSort(void *v[], int left, int right, int (*comp)(void *, void *));
void WriteText(line *lineptrs[], int nlines, int out_ind,char *filepath);
void FreeMemory(line* lineptrs[], int nlines);
int RevStrcmp(line* line1, line* line2);
int MyStrcmp(line *line1, line *line2);

#define MAXLINES 5000
line *lineptrs[MAXLINES];

int main(int argc, char *argv[]) {

    int i = 0;
    char *in_path, *al_out_path, *rev_out_path;

    switch (argc) {
        case 1 : // reads from default file and outputs result to console
            in_path = (char*)"/home/alexey/CLionProjects/Onegin_2/Onegin"; // cahnge to your defualt path
            printf("File reading from default path: %s\n", in_path);

            al_out_path = "";
            rev_out_path = "";

            break;
        case 2: // reads from user file and outputs to console
            in_path = argv[++i];
            printf("File reading from: %s\n", in_path);

            al_out_path = "";
            rev_out_path = "";

            break;
        case 3: // reads from user file and output alph. order in user file, and rev. order to console
            in_path = argv[++i];
            printf("File reading from: %s\n", in_path);

            al_out_path = argv[++i];
            printf("File with sorted in alphabet order text: %s\n", al_out_path);

            rev_out_path = "";

            break;
        case 4: // reads and outputs to user files
            in_path = argv[++i];
            printf("File reading from: %s\n", in_path);

            al_out_path = argv[++i];
            printf("File with sorted in alphabet order text: %s\n", al_out_path);

            rev_out_path = argv[++i];
            printf("File with sorted in reversed alphabet order text: %s\n", rev_out_path);

            break;
        default: // too much arguments
            printf("Wrong command line arguments");
    }

    FILE* file;
    file = fopen(in_path, "r");

    int nlines = GetText(lineptrs, MAXLINES, file);

    if (nlines >= 0)
    {
        printf("Alphabet order: %s\n", al_out_path);
        qSort((void**) lineptrs, 0, nlines - 1, (int (*)(void*, void*))(MyStrcmp));
        WriteText(lineptrs, nlines, argc, al_out_path);

        printf("Reverse alphabet order %s:\n", rev_out_path);
        qSort((void **) lineptrs, 0, nlines-1, (int (*)(void*, void*))(RevStrcmp));
        WriteText(lineptrs, nlines, argc, rev_out_path);

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
