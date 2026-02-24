//
// Created by gusta on 18/11/2025.
//

#ifndef ED_DOBLELINKEDLIST_H
#define ED_DOBLELINKEDLIST_H

#define SUCCESS 0
#define LIST_EMPTY 1
#define MEMORY_FULL 2
#define ID_NOT_FOUND 3
#define INVALID_INDEX 4

typedef struct {
    int id;
    double qty;
} Data;

typedef struct Node {
    Data data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* start;
    Node* end;
    int n;
} List_DL;

void initList(List_DL *list);
Node* createNode(Data data);
int isEmpty(const List_DL *list);
int listSize(const List_DL *list);

int insertStart(List_DL *list, Node* node);
int insertEnd(List_DL *list, Node* node);
int insertAfter(List_DL *list, int id, Data data);

void popNode(Node *node, Data *out);
int removeStart(List_DL *list, Data *out);
int removeEnd(List_DL *list, Data *out);
int removeByID(List_DL *list, int id, Data *out);

int getByID(const List_DL *list, int id, Data *out);
void printList(const List_DL *list);

#endif //ED_DOBLELINKEDLIST_H