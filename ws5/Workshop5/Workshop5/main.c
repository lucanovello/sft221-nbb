#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
int main(void)
{
	//char testStr[] = { "This is a\n string with embedded newline character and \n12345 numbers inside it as well 67890" };
	char testStr[] = { "This is a\n string with 111 embedded newline character and \n123456 numbers 321 inside 654 it as well 67890 extra words" };
	struct StringIndex index = indexString(testStr);
	int i;
	printf("\"%s\"", testStr);
	printf("\n");
	printf("---------------------------------------------------------------------------------------------------------");
	printf("\n");
	printf("LINES: %d\n", index.numLines);
	for (i = 0; i < index.numLines; i++)
	{
	printUntil(index.str, index.lineStarts[i], '\n');
	printf("\n");
	}
	printf("----------------------------");
	printf("\nWORDS: %d\n", index.numWords);
	for (i = 0; i < index.numWords; i++)
	{
	printUntilSpace(index.str, index.wordStarts[i]);
	printf("\n");
	}
	printf("----------------------------");
	printf("\nNUMBERS: %d\n", index.numNumbers);
	for (i = 0; i < index.numNumbers; i++)
	{
	printUntilSpace(index.str, index.numberStarts[i]);
	printf("\n");
	}
	printf("---------------------------------------------------------------------------------------------------------");
	return 0;
	}