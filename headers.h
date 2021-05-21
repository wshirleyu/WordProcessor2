/* CS2211a 2020 */
/* Assignment 05 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 30, 2020 */

#ifndef ASN5_HEADERS_H
#define ASN5_HEADERS_H

#include "definitions.h"

//LIST* inputFunc();
sentences inputFunction();
char outputFunc(sentences outputStruct);
//list* createList(void);
words* createWordList(void);
sentences* createSentList(void);
bool insertWord(words *wordList, text* word);
bool insertLine(sentences* sentList, line* sentence);
void removeLine(sentences* sentList, int lineNum);
void printSentList(sentences* sentList);

#endif //ASN5_HEADERS_H
