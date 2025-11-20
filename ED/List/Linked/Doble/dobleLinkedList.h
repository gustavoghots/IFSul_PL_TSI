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

#endif //ED_DOBLELINKEDLIST_H