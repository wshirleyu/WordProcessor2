/* CS2211a 2020 */
/* Assignment 05 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 30, 2020 */

#include "headers.h"

// function to create linked list of words
words* createWordList(void){
    // dynamically allocate memory for linked list
    words* wordList;
    wordList = (words*)malloc(sizeof(words));
    if (wordList){
        wordList->head = NULL;
        wordList->count=0;
    }
    return wordList;
}

// function to create linked list of sentences
sentences* createSentList(void){
    // dynamically allocate memory for linked list
    sentences* sentList;
    sentList = (sentences*)malloc(sizeof(sentences));
    if (sentList){
        sentList->head=NULL;
        sentList->count=0;
    }
    return sentList;
}

// function to add to linked list of words
bool insertWord(words *wordList, text* word){

    // create temporary word node and set as head of wordList
    text* newWord = word;
    text* lastWord = wordList->head;

    // assign data from the word node
    newWord->numChar=word->numChar;
    newWord->charPtr=word->charPtr;
    newWord->position = word->position;
    wordList->count++;

    // if the head node is null, then the list is empty
    if (wordList->head == NULL){
        wordList->head = newWord;
        return true;
    }
    else{
        // iterate until node with next pointing to null
        while (lastWord->next !=NULL){
            lastWord = lastWord->next;
        }
        // set the next pointer from null to the new node
        lastWord->next = newWord;
    }
    return true;
}

// function to add to linked list of sentences
bool insertLine(sentences* sentList, line* sentence) {

    // create temporary word node and set as head of sentList
    line *newLine = sentence;
    line *lastLine = sentList->head;

    // assign data from the sentence node
    newLine->lineNum = sentence->lineNum;
    newLine->numWords = sentence->numWords;
    newLine->sentHead = sentence->sentHead;
    newLine->numWords++;

    // if the head node is null, then the list is empty
    if (sentList->head == NULL) {
        sentList->head = newLine;
        sentList->count++;
        return true;
    } else {
        // iterate until node with next pointing to null
        while (lastLine->next != NULL) {
            lastLine = lastLine->next;
        }
        // set the next pointer from null to the new node
        lastLine->next = newLine;
        sentList->count++;
    }
    return true;
}
