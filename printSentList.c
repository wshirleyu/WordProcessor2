/* CS2211a 2020 */
/* Assignment 05 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 30, 2020 */
#include "definitions.h"

//function to print the linked list of sentence nodes
void printSentList(sentences* sentList){

    // set pointer to sentence list head
    line* lineTmp = sentList->head;

    // iterate sentence list until hitting null
    while (lineTmp!=NULL){
        // set pointer to head of word list
        text* wordTmp = lineTmp->sentHead;
        // iterate word list until hitting null
        while (wordTmp!=NULL){
            // set pointer to character pointer
            char *word = wordTmp->charPtr;
            // print words
            for (int i=0; i<wordTmp->numChar; i++){
                printf("%c", *(word+i));
            }
            wordTmp = wordTmp->next;
            printf(" ");
        }
        lineTmp = lineTmp->next;
        printf("\n");
    }
}
