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

	for(size_t i(0) ; i < str->pos ; ++i)
		std::cout << str->str[i];

	displayStr(str->next);
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
	const size_t len(21);
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

		for (size_t i(0), posA(0), posB(0) ; i < len ; ++i, ++posA, ++posB)
		{
			if (i < a->pos)
				bufferA[posA] = a->str[i]; // Adding every non-space character to the buffer
			else
				bufferA[posA] = '\0'; // End of the string, we don't care if this character is repeated

			if (i < b->pos)
				bufferB[posB] = std::tolower(b->str[i]); // Adding every non-space character to the buffer
			else
				bufferB[posB] = '\0'; // End of the string, we don't care if this character is repeated
		}

		int cmp = strcoll(bufferA, bufferB); // Finally comparing our strings
		if (cmp != 0)
			return cmp; // Those are not equal

		a = a->next;
		b = b->next;
	}
}
