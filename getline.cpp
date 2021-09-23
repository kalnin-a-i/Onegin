# include <stdio.h>

int getline(char *line, FILE *file, int maxlen)
{
    char c;
    int i = 0;

    while ((c = (char)getc(file)) != '\n' && i < maxlen && c != EOF)
    {
        if (c != '?' && c != '!' && c != ',' && c != '.' && c != ';' && c != ':'){
            *(line + i) = c;
            i++;
        }
    }
    if (c == '\n' || c == EOF)
    {
        *(line + i) = '\0';
    }
    if (i >= maxlen)
    {
        return -1;
    }
    return i;
}