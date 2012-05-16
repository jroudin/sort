#include "dynstr.hpp"

DynStr* addChar(DynStr* str, const char c)
{
	DynStr* s = str;
	if (s == NULL)
	{
		// Creating the tail of the string
		s = new DynStr;
		s->pos = 0;
		s->next = NULL;
	}

	if (s->pos >= sizeof s->str)
	{
		s->next = addChar(NULL, c);
		return s->next; // Returning the head
	}
	else
	{
		s->str[s->pos++] = c;
		return s; // We're still on the head at this moment
	}
}

void displayStr(DynStr* str)
{
	if (str == NULL)
	{
		// End of this str, let's printing a new line
		std::cout << std::endl;
		return;
	}

	for(int i(0) ; i < str->pos ; ++i)
		std::cout << str->str[i];

	displayStr(str->next);
}

void freeStr(DynStr* str)
{
	if (str == NULL)
		return;

	DynStr* next = str->next;
	delete str;

	if (next != NULL)
		freeStr(next);
}

int compareStr(DynStr* a, DynStr* b)
{
	const int len(21);
	char bufferA[len], bufferB[len];

	// This function is not recursive in order to create only two string of 21chars (bufferA, bufferB)
	// If it was recursive, every strings would be kept until the final return value would be determined

	while(true)
	{
		if (a == NULL && b == NULL) // So, a == b
			return 0;
		else if (a == NULL && b != NULL) // So, a < b
			return -1;
		else if (a != NULL && b == NULL) // So, a > b
			return 1;

		// Otherwise : 

		for (int i(0), posA(0), posB(0) ; i < len ; ++i, ++posA, ++posB)
		{
			if (i < a->pos && ((a->str[i] >= 'a' && a->str[i] <= 'z') || (a->str[i] >= 'A' && a->str[i] <= 'Z') || (a->str[i] >= '0' && a->str[i] <= '9')))
				bufferA[posA] = std::tolower(a->str[i]); // Adding every non-space character to the buffer
			else if (i >= a->pos)
				bufferA[posA] = '\0'; // End of the string, we don't care if this character is repeated
			else
				--posA; // The character was a spacer : we stay at the current pos

			if (i < b->pos && ((b->str[i] >= 'a' && b->str[i] <= 'z') || (b->str[i] >= 'A' && b->str[i] <= 'Z') || (b->str[i] >= '0' && b->str[i] <= '9')))
				bufferB[posB] = std::tolower(b->str[i]); // Adding every non-space character to the buffer
			else if (i >= b->pos)
				bufferB[posB] = '\0'; // End of the string, we don't care if this character is repeated
			else
				--posB; // The character was a spacer : we stay at the current pos
		}

		int cmp = strcmp(bufferA, bufferB); // Finally comparing our strings
		if (cmp != 0)
			return cmp; // Those are not equal

		a = a->next;
		b = b->next;
	}
}
