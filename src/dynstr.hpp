#ifndef DYN_STR_HPP
#define DYN_STR_HPP
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>

// Linked list strings
struct DynStr
{
	char str[20];
	size_t pos;
	DynStr* next;
};

DynStr* addChar(DynStr* str, const char c);
void displayStr(DynStr* str);
void freeStr(DynStr* str);
int compareStr(DynStr* a, DynStr* b);

#endif // DYN_STR_HPP
