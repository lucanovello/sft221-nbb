#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include "log4c.h"
int main(void)
{
	// create log struct, open and check log file
	char errMsg[L4C_ERROR_MSG_MAX + 1] = { 0 };
	struct Log4cStruct log = l4cOpen("log.txt", 0);
	if (l4cCheck(&log, errMsg)) {
		printf("%s\n", errMsg);
		return 1;
	}

	char testStr[] = { "This is a\n string with embedded newline character and \n12345 numbers inside it as well 67890" };
	struct StringIndex index = indexString(testStr);
	int i;

	// StringIndex complete
	l4cPrintf(&log, L4C_INFO, "testStr = '%s'", testStr);
	l4cInfo(&log, "String Index complete");

	printf("LINES: %d\n", index.numLines);
	for (i = 0; i < index.numLines; i++)
	{
	printUntil(index.str, index.lineStarts[i], '\n');
	printf("\n");
	}
	
	// LINES print complete
	l4cPrintf(&log, L4C_INFO, "numLines = %d", index.numLines);
	l4cInfo(&log, "LINES print complete");

	printf("\nWORDS: %d\n", index.numWords);
	for (i = 0; i < index.numWords; i++)
	{
	printUntilSpace(index.str, index.wordStarts[i]);
	printf("\n");
	}

	// WORDS print complete
	l4cPrintf(&log, L4C_INFO, "numWords = %d", index.numWords);
	l4cInfo(&log, "WORDS print complete");

	printf("\nNUMBERS: %d\n", index.numNumbers);
	for (i = 0; i < index.numNumbers; i++)
	{
	printUntilSpace(index.str, index.numberStarts[i]);
	printf("\n");

	// NUMBERS print complete
	l4cPrintf(&log, L4C_INFO, "numNumbers = %d", index.numNumbers);
	l4cInfo(&log, "NUMBERS print complete");
	// close file
	l4cClose(&log);
	}
	return 0;
	}