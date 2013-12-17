
/**********************************************************************
 * cdecl.c
 *
 * A program written to translate C declarations into English
 *
 * Problem found in "Expert C Programming" - P. van der Linden
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 64


// The stack data structure to hold tokens
struct token
{
    char type;
    char string[MAX_TOKEN_LEN];
};

// Holds tokens we read before reaching first identifier
struct token stack[MAX_TOKENS];

// Holds the token just read
struct token this;


