///* CS2211a 2020 */
///* Assignment 05 */
///* Shirley Wu */
///* 251082034 */
///* SWU546 */
///* NOV 30, 2020 */
//#include "definitions.h"
//bool insertList (LIST* list, void* itemPtr){
//
//    NODE* newPtr;
//    if (!(newPtr = (NODE*)malloc(sizeof(NODE))))
//        return false;
//
//    newPtr->dataPtr = itemPtr;
//    newPtr->next = list->head;
//
//    (list->count)++;
//    list->head = newPtr;
//    return true;
//
//}