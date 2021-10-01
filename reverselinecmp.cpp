#include "string.h"
#include "assert.h"
#include "line.h"

//------------------------------------------------------------------------
/** @file */
//! Compares two strings from the end
//! @param[in] line1 1st string and it`s length
//! @param[in] line2 2d string and it`s length
//! @return positive number if str2 > str1, 0 if str1 = str2, otherwise 0
//-------------------------------------------------------------------------
int RevStrcmp(line* line1, line* line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    int i = 0;

    while (i < line1->len && i < line2->len)
    {
        if (line1->str[line1->len - i - 1] != line2->str[line2->len - i - 1])
        {
            return line1->str[line1->len - i - 1] - line2->str[line2->len - i - 1];
        }
        i++;
    }
    return line1->len -line2->len;
}
