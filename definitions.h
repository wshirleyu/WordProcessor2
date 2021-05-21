/* CS2211a 2020 */
/* Assignment 05 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 30, 2020 */

#ifndef ASN5_DEFINITIONS_H
#define ASN5_DEFINITIONS_H
#include "ctype.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#endif //ASN5_DEFINITIONS_H

typedef struct word {
    char *charPtr;    //pointer to a character
    int numChar;      // integer stores the number of characters in the word
    int position;    // inter to store position of the word in the sentence it's contained in
    struct word* next; // pointer to next word
} text;     // alias for word struct

typedef struct sentence {
    struct word *sentHead;// pointer to head in word list
    int lineNum; // integer storing the line number
    int numWords; // integer storing number of words in a line
    struct sentence* next; // pointer to next sentence
} line; // alias for sentence struct

typedef struct sentList{
    int count;
    line *head;
} sentences; //alias for sentence linked list

// control structure - retains address of first node in list
typedef struct wordList
{
    int count;
    text *head;

} words; // alias for word linked list

