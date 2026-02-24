//
// Created by gusta on 18/11/2025.
//

#ifndef ED_LIST_H
#define ED_LIST_H

#define SUCCESS 0
#define LIST_EMPTY 1
#define MEMORY_FULL 2
#define ID_NOT_FOUND 3
#define INVALID_INDEX 4

#include "../structs/util.h"

void list_initList(List *list);
ListNode* list_createNode(Data data);
int list_isEmpty(const List *list);
int list_size(const List *list);

int list_insertStart(List *list, ListNode* node);
int list_insertEnd(List *list, ListNode* node);
int list_insert(List *list, int index, Data data);
int list_insertAfter(List *list, int id, Data data);

void list_popNode(ListNode *node, Data *out);
int list_removeStart(List *list, Data *out);
int list_removeEnd(List *list, Data *out);
int list_removeByID(List *list, int id, Data *out);

int list_getByID(const List *list, int id, Data *out);
void list_printList(const List *list);

#endif //ED_LIST_H