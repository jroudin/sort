#include "dynstr.hpp"

DynStr* addChar(DynStr* str, const char c)
{
    DynStr* s = str;
    if (s == NULL)
    {
        // Creating the tail of the string
        s = new DynStr;
        s->str[0] = '\0'; // Initializing our string
        s->next = NULL;
    }

    if ((strlen(s->str)+1) >= sizeof s->str)
    {
        s->next = addChar(NULL, c);
        return s->next; // Returning the head
    }
    else
    {
        strncat(s->str, &c, 1); // Adding the character to the str

        // Notice we use strncat with the num parameter set as 1
        // in order to copy the sole character and not depend of \0
        // which will not appear since it is a character
        // sprintf is too much for this use... 

        return s; // We're still on the head at this moment
    }
}

void displayStr(DynStr* s)
{
    if (s == NULL)
    {
        // End of this str, let's printing a new line
        std::cout << std::endl;
        return;
    }

    std::cout << s->str;
    displayStr(s->next);
}

void freeStr(DynStr* str)
{
    if (str == NULL)
        return;

    freeStr(str->next);
    delete str;
}

int compareStr(DynStr* a, DynStr* b)
{
    int cmp(0);
    if (a == NULL && b == NULL) // So, a == b
        return 0;
    else if (a == NULL && b != NULL) // So, a < b
        return -1;
    else if (a != NULL && b == NULL) // So, a > b
        return 1;

    // Otherwise : 

    cmp = strcoll(a->str, b->str); // comparing our strings
    if (cmp != 0)
        return cmp; // Those are not equal

    // Strings are equal : let's proceed comparing with the next sequences... 
    return compareStr(a->next, b->next);
}
