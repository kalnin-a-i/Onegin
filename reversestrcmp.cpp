#include "string.h"
#include "assert.h"
#include "line.h"

//------------------------------------------------------------------------
/** @file */
//! Compares two strings from the end
//! @param[in] str1 1st string
//! @param[in] 2d string
//! @return positive number if str2 > str1, 0 if str1 = str2, otherwise 0
//-------------------------------------------------------------------------
int RevStrcmp(line* line1, line* line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    int i = 0;
    int len1 = line1->len;
    int len2 = line2->len;
    char *str1 = line1->str;
    char *str2 = line2->str;
    while (i < len1 && i < len2)
    {
        if (str1[len1 - i - 1] != str2[len2 - i - 1])
        {
            return str2[len2 - i - 1] - str1[len1 - i - 1];
        }
        i++;
    }
    return len2 - len1;
}

/*void CheckRev(char *str1, char *str2, int answer)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    if (answer * RevStrcmp(str1, str2) > 0)
    {
        printf("OK\n");
        return;
    }
    if (answer == 0 && RevStrcmp(str1, str2) == 0)
    {
        printf("OK\n");
        return;
    }
    printf("FAIL %s\t%s\n", str1, str2);
}

void TestRev()
{
    printf("Tests for RevStrcmp\n");
    CheckRev("abcd", "dcba", -1);
    CheckRev("abcd", "edcba", -1);
    CheckRev("asdf", "asdf", 0);
    CheckRev("asdfg", "asdfk", 1);
    CheckRev("f", "k", 1);
    CheckRev("fk", "kkk", 1);
}*/