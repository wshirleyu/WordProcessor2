/* CS2211a 2020 */
/* Assignment 05 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 30, 2020 */

#include "definitions.h"

// function to remove a line from the sentence linked list by line number
void removeLine(sentences* sentList, int lineNum){

    // set temporary pointers to head and previous of sentList
    line *tmp = sentList->head;
    line *prev;

    // check if node is null and if line number corresponds to input number
    if (tmp!=NULL && tmp->lineNum == lineNum){
        // reassign head pointer
        sentList->head = tmp->next;
        // iterate from the node after node removed and update line numbers
        line* temp = tmp->next;
        while (temp!=NULL){
            temp->lineNum--;
            temp = temp->next;
        }
        // free memory of removed node
        text *delWord = tmp->sentHead;
        free(delWord->charPtr);
        free(delWord);
        free(tmp);
        return;
    }
    // iterate through sentence list until tmp is null
    while (tmp!=NULL && tmp->lineNum != lineNum){
        prev = tmp;
        tmp =tmp->next;
    }

    // check if list is empty or node is null
    if (tmp == NULL) {
        return;
    }

    prev->next = tmp->next;
    line* temp = tmp->next;

    // iterate and update line numbers
    while (temp!=NULL){
        temp->lineNum--;
        temp = temp->next;
    }
    // free memory of removed node
    text *delWord = tmp->sentHead;
    free(delWord->charPtr);
    free(delWord);
    free(tmp);
}
