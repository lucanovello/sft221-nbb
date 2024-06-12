#define _CRT_SECURE_NO_WARNINGS
#include "stringhelp.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "log4c.h"

int nextWhite(const char* str)
{
	assert(str != NULL);	// check if str is null
	int i, result = -1;
	for (i = 0; result < 0 && str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			result = i;
		}
	}
	return ((result * -1) != result) ? i : result;
}
int isNumber(const char* str, const int len)
{
	assert(str != NULL);	// check if str is null
	assert(len >= 0);		// check len is not negative
	int result;
	for (result = 1; result <= len && result; result++)
	{
		if (!isdigit(str[result - 1])) result = -1;
	}
	return result;
}
struct StringIndex indexString(const char* str)
{
	assert(str != NULL);	// check if str is null
	struct StringIndex result = { {0}, {0}, {0}, 0, 0, 0 };
	char buf[MAX_WORD_SIZE + 1] = { 0 };
	int i, sp;
	strcpy(result.str, str);
	if (str[0] != '\0')
	{
		result.lineStarts[0] = 0;
		result.numLines = 1;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		while (isspace(str[i]))
		{
			if (str[i] == '\n')
			{
				result.lineStarts[result.numLines++] = i + 1;
			}
			i++;
		}
		for (sp = 0; str[sp + i] != '\0' && !isspace(str[sp + i]); sp++);
		if (isNumber(str + i, sp))
		{
			result.numberStarts[result.numNumbers++] = i;
		}
		else
		{
			result.wordStarts[result.numWords++] = i;
		}
		i += sp - 1;
	}
	return result;
}
int getNumberLines(const struct StringIndex* idx)
{
	assert(idx != NULL);	// check if idx is NULL
	return idx->numLines;
}
int getNumberWords(const struct StringIndex* idx)
{
	assert(idx != NULL);	// check if idx is NULL
	return idx->numWords;
}
int getNumberNumbers(const struct StringIndex* idx)
{
	assert(idx != NULL);	// check if idx is NULL
	return idx->numNumbers;
}
void getWord(char word[], const struct StringIndex* idx, int wordNum)
{
	assert(idx != NULL);	// check if idx is NULL
	assert(word != NULL);	// check if word is NULL
	assert(wordNum >= 0);   // check if less than or equal to zero

	int i, sp, start;
	word[0] = '\0';
	if (wordNum < idx->numWords && wordNum >= 0)
	{
		start = idx->wordStarts[wordNum];
		sp = nextWhite(idx->str + start);
		for (i = 0; i <= sp; i++)
		{
			word[i] = idx->str[start + i];
		}
		word[sp] = '\0';
	}
}
void getNumber(char word[], const struct StringIndex* idx, int numberNum)
{
	assert(idx != NULL);	// check if idx is NULL
	assert(word != NULL);	// check if word is NULL
	assert(numberNum >= 0);	// check if numberNum is less than or equal to zero

	int i, sp, start;
	word[0] = '\0';
	if (numberNum < idx->numNumbers && numberNum >= 0)
	{
		start = idx->numberStarts[numberNum];
		sp = nextWhite(idx->str + start);
		for (i = 0; i < sp; i++)
		{
			word[i] = idx->str[sp + i];
		}
		word[sp] = '\0';
	}
}
char* getLine(struct StringIndex* idx, int lineNum)
{
	assert(idx != NULL);	// check if idx is NULL
	assert(lineNum >= 0);	// check if lineNum is less than or equal to zero

	char* result = NULL;
	if (lineNum < idx->numLines && lineNum >= 0)
	{
		result = idx->str + idx->lineStarts[lineNum];
	}
	return result;
}
void printUntil(const char* s, const int start, const char terminator)
{
	assert(s != NULL);      // check if s is NULL
	assert(start >= 0);     // check if start is less than or equal to zero

	int i;
	for (i = start; s[i] != '\0' && s[i] != terminator; i++)
		printf("%c", s[i]);
}
void printUntilSpace(const char* s, const int start)
{
	assert(s != NULL);      // check if s is NULL
	assert(start >= 0);     // check if start is less than or equal to zero

	int i;
	for (i = start; s[i] != '\0' && !isspace(s[i]); i++)
		printf("%c", s[i]);
}