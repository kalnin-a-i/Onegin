#include "line.h"
#include "stdio.h"
#include "assert.h"

int MyStrcmp(line *line1, line *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    char *str1 = line1->str;
    char *str2 = line2->str;

    while (*str1 != '\0')
    {
        if (*str1 != *str2)
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
