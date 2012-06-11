#ifndef DYN_STR_HPP
#define DYN_STR_HPP
#include <iostream>
#include <cstring>

// Linked list strings
struct DynStr
{
    char str[21];
    DynStr* next;
};

DynStr* addChar(DynStr* str, const char c);
void displayStr(DynStr* str);
void freeStr(DynStr* str);
bool isBlank(DynStr* s);
int compareStr(DynStr* a, DynStr* b);

#endif // DYN_STR_HPP
