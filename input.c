///* CS2211a 2020 */
///* Assignment 05 */
///* Shirley Wu */
///* 251082034 */
///* SWU546 */
///* NOV 30, 2020 */
//#include "headers.h"
//
//output inputFunc() {
//
//    int sizeWordList = 0;
//    words* wordList = createWordList();
//    sentences* sentList = createSentList();
//
//    char allInput[1000]= ""; // master char array stores all char inputs
//    int pos = 0; // tracks position of first empty index after input
//
//    int lineCount = 0;
//    int wordCountTest = 0;
//
//    while(wordCountTest == 0) {
//        int charCount = 0;
//        wordCountTest = 0;
//
//        //char *nullTest = (char *) malloc(100*sizeof(char));
//        char *nullTest = (char*) calloc(100, sizeof(char)); // memory array to check for null input
//
//        printf("\nEnter a String:  \n"); //prompt for user input
//        fgets(nullTest, 100, stdin); // read line
//        nullTest[strlen(nullTest)-1] = '\0';
//        int posInLine = 0; //tracks position of word in user input line
//
//        // check if entry is null and break loop if it is
//        if (nullTest[0] == '\0') {
//            free(nullTest);
//            wordCountTest=1;
//            break;
//        } else {
//            strcat(allInput, nullTest); // if the user input is not null or empty, concatenate to master char array
//            free(nullTest); //reset the values that have been assigned to allocated memory of nullTest
//        }
//
//        // iterating through the master char array allInput
//        while (allInput[pos] != '\0') {
//                char *charPtr =&allInput[pos];
//                // check if first char of latest input is a space
//                if (!isspace(allInput[pos])) {
//                    charCount = 0;
//
//                    while (!isspace(allInput[pos]) && allInput[pos] != '\0') {
//                        pos++;
//                        charCount++;
//                        // make char memory array with length of charCount
//                        // loop through allInput up to space and use pointer arithmetic to store chars
//
//
//                    }
//                    text *newWord = (text *) malloc(sizeof(text));
//                    newWord->c = charPtr;
//                    newWord->numChar = charCount;
//                    newWord->position = posInLine + 1;
//                    insertWord(wordList, newWord);
//
//                    // create pointer for first word in the input line
//                    // add pointer to sentence struct
//
//                    posInLine++; // increase tracker of word position in the current input line
//
//
//                } else {
//                    pos++;
//                }
//
//
//
//        }
//        // if the loop reaches a null char , the position of that char is the end of the input
//        if (allInput[pos] == '\0') {
//
//            allInput[pos]=' ';
//            pos++;
//
//            // check case if sentence doesn't contain any words
//            if (posInLine==0){
//                wordCountTest=1;
//                break;
//            }
//            // increase sentence counter
//            lineCount++;
//            // add values of sentence struct
//            line *newLine = (line*)malloc(sizeof(line));
//            newLine->sentHead = wordList->head;
//            newLine->sentTail = wordList->tail;
//            newLine->numWords = posInLine;
//            newLine->lineNum = lineCount;
//            insertLine(sentList,newLine);
//
//        }
////        insertList(genList, *sentList);
////        genList->count++;
//    }
//
////total lines from input and pointer to structure
////    output *outputStruct = (output *)calloc(1000, sizeof(output));
////    outputStruct->sentence = ptrSentList;
////    outputStruct->returnLineNum = lineCount;
////    return outputStruct;
//
//    output *returnStruct = (output *)malloc(sizeof(output));
//    returnStruct->sentList = sentList;
//    returnStruct->wordList = wordList;
//    return *returnStruct;
//}