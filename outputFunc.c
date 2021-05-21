/* CS2211a 2020 */
/* Assignment 04 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 30, 2020 */
#include "headers.h"

// function to process output from user
// input
char outputFunc(sentences sentList) {

    // explain output 1
    printf("\nThis is all the words printed out on the same line as entered: \n");
    printSentList(&sentList);

    //output 2 prompts user for a word to search existing entries and compare, then return line and pos num
    char *searchInput = (char *) calloc(100, sizeof(char)); // memory array to check for null input
    int inputTest = 0;

    while (inputTest == 0) {
        printf("\nEnter a word to search: "); // prompt user input
        fgets(searchInput, 30, stdin); //read word to be searched
        searchInput[strlen(searchInput) - 1] = '\0';

        bool found = false;
        //check if input is null
        if (searchInput[0] == '\0' || isspace(searchInput[0])) {
            inputTest = 1;    // exit loop if search input is null or is a space
            break;
        } else {
            // set temporary pointers to list head nodes
            // traverse each list until node
            line *lineTmp = sentList.head;
            while (lineTmp != NULL) {
                text *wordTmp = lineTmp->sentHead;
                while (wordTmp != NULL) {
                    // allocate memory to store word node to compare
                    char *word = wordTmp->charPtr;
                    char *compareStr = (char *) calloc(40, sizeof(char));
                    for (int i = 0; i < wordTmp->numChar; i++) {
                        compareStr[i] = word[i];
                    }
                    // use strcmp to compare
                    if (strcmp(compareStr, searchInput) == 0) {
                        found = true;
                        for (int i=0; i<sizeof(searchInput); i++){
                            printf("%c", searchInput[i]);
                        }
                        printf(" found in line %d position %d\n", lineTmp->lineNum, wordTmp->position);
                    } else {
                        free(compareStr);
                    }
                    wordTmp = wordTmp->next;
                }
                lineTmp = lineTmp->next;
            }
            if (found == false){
                printf("Word not found.");
            }
        }
    }

    //output 3 prompts user for a line to remove from the linked list
    int testInput = 0;
    char *removeInput = (char*)malloc(sizeof(char));

    int updateSize = sentList.count;
    while (testInput == 0) {

        if (updateSize==0){
            printf("List is empty.");
            break;
        }
        printf("\nEnter a line number to remove: "); // prompt user input
        fgets(removeInput, 30, stdin); //read word to be searched
        removeInput[strlen(removeInput) - 1] = '\0';


        // check for exit condition
        if (removeInput == '\0' || removeInput == " ") {
            testInput = 1;    // exit loop if search input is null or is a space
            break;

        }else{
            // convert input to integer value
            int removeNum = atoi(removeInput);
            if (removeNum == 0){
                printf("Program terminated.");
                break;
            }
            int size = sentList.count;

            if (removeNum > sentList.count){        // check if removal value is valid
                printf("Request denied: Line number out of scope. Please try again.");
            }
            else{
                if (updateSize>0){
                   removeLine(&sentList, removeNum);
                   updateSize--;

                   printf("Remaining lines: \n");   // print remaining sentences inlist
                   line* lineTmp = sentList.head;
                   while (lineTmp!=NULL){   // traverse through sentence and word lists
                       text* wordTmp = lineTmp->sentHead;
                       while (wordTmp!=NULL){
                           char *word = wordTmp->charPtr;
                           for (int i=0; i<wordTmp->numChar; i++){
                               printf("%c", *(word+i));
                           }
                           wordTmp = wordTmp->next;
                           printf(" ");
                       }
                       lineTmp = lineTmp->next;
                       printf("\n");
                   }
                } else{
                    printf("List is empty.");   // check if list has been completely emptied
               }
            }
        }
    }
}