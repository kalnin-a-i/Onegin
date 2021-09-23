# include <stdio.h>

//----------------------------------------------------------------
/** @file */
//! Reads line from text file ignoring spaces and punctuation marks
//! @param[in] line pointer to string where reads line
//! @param[in] file pointer to file from we read
//! @param[in] maxlen maximal length of line
//! @return number of symbols in line
//! @note if returns 0 line = "\0"
//! @note if return -1 length of line > maximal length
//-----------------------------------------------------------------
int GetLine(char *line, FILE *file, int maxlen)
{
    char c;
    int i = 0;

    while ((c = (char)getc(file)) != '\n' && i < maxlen && c != EOF)
    {
        if (c != '?' && c != '!' && c != ',' && c != '.' && c != ';' && c != ':' && c != ' '){
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