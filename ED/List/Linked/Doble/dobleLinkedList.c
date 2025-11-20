//
// Created by gusta on 18/11/2025.
//

#include "dobleLinkedList.h"

#include <stdlib.h>

Node* createNode(Data data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

void initList(List_DL *list) {
    list->start = nullptr;
    list->end = nullptr;
    list->n = 0;
}

int insertStart(List_DL *list, Node* node) {
    node->prev = nullptr;
    node->next = list->start;

    if (list->n > 0)
        list->start->prev = node;
    list->start = node;

    if (list->n == 0)
        list->end = node;

    list->n++;
    return SUCCESS;
}


int insertEnd(List_DL *list, Node* node) {
    node->next = nullptr;
    node->prev = list->end;

    if (list->n > 0)
        list->end->next = node;
    list->end = node;

    if (list->n == 0)
        list->start = node;

    list->n++;
    return SUCCESS;
}


int insert(List_DL *list, const int index, const Data data) {
    if (index < 0 || index > list->n)
        return INVALID_INDEX;

    Node* newNode = createNode(data);
    if (newNode == nullptr)
        return MEMORY_FULL;

    if (index == 0)
        return insertStart(list, newNode);

    if (index == list->n)
        return insertEnd(list, newNode);

    Node* temp = list->start;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;

    list->n++;

    return SUCCESS;
}

int removeStart(List_DL *list, Data *out) {
    if (list->n == 0)
        return LIST_EMPTY;

    Node* temp = list->start;
    *out = temp->data;

    list->start = temp->next;

    if (list->start != nullptr)
        list->start->prev = nullptr;
    else
        list->end = nullptr; // lista ficou vazia

    free(temp);
    list->n--;

    return SUCCESS;
}

int removeEnd(List_DL *list, Data *out) {
    if (list->n == 0)
        return LIST_EMPTY;

    Node* temp = list->end;
    *out = temp->data;

    list->end = temp->prev;

    if (list->end != nullptr)
        list->end->next = nullptr;
    else
        list->start = nullptr; // lista ficou vazia

    free(temp);
    list->n--;

    return SUCCESS;
}

int removeAt(List_DL *list, const int index, Data *out) {
    if (index < 0 || index >= list->n)
        return INVALID_INDEX;

    if (index == 0)
        return removeStart(list, out);

    if (index == list->n - 1)
        return removeEnd(list, out);

    Node* temp = list->start;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    *out = temp->data;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
    list->n--;

    return SUCCESS;
}

int get(const List_DL *list, const int index, Data *out) {
    if (index < 0 || index >= list->n)
        return INVALID_INDEX;

    Node* temp;

    if (index < list->n / 2) {
        temp = list->start;
        for (int i = 0; i < index; i++)
            temp = temp->next;
    } else {
        temp = list->end;
        for (int i = list->n - 1; i > index; i--)
            temp = temp->prev;
    }

    *out = temp->data;
    return SUCCESS;
}
