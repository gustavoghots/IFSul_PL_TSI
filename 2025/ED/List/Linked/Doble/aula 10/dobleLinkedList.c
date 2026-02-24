//
// Created by gusta on 18/11/2025.
//

#include "dobleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

Node* createNode(const Data data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int isEmpty(const List_DL *list) {
    if (list->n == 0)
        return LIST_EMPTY;
    return SUCCESS;
}

void initList(List_DL *list) {
    list->start = NULL;
    list->end = NULL;
    list->n = 0;
}

int listSize(const List_DL *list) {
    return list->n;
}

int insertStart(List_DL *list, Node* node) {
    node->prev = NULL;
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
    node->next = NULL;
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
    if (newNode == NULL)
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

int insertAfter(List_DL *list, const int id, const Data data) {
    // Lista vazia
    if (list->n == 0)
        return ID_NOT_FOUND;

    Node* temp = list->start;

    // Buscar pelo id
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    // Não encontrou
    if (temp == NULL)
        return ID_NOT_FOUND;

    // Criar novo
    Node* newNode = createNode(data);
    if (newNode == NULL)
        return MEMORY_FULL;

    newNode->data = data;

    if (temp->next == NULL)
        return insertEnd(list, newNode);

    // Insere depois temp
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    list->n++;
    return SUCCESS;
}

int removeStart(List_DL *list, Data *out) {
    if (isEmpty(list))
        return LIST_EMPTY;

    Node* temp = list->start;
    *out = temp->data;

    list->start = temp->next;

    if (list->start != NULL)
        list->start->prev = NULL;
    else
        list->end = NULL; // lista ficou vazia

    free(temp);
    list->n--;

    return SUCCESS;
}

int removeEnd(List_DL *list, Data *out) {
    if (isEmpty(list))
        return LIST_EMPTY;

    Node* temp = list->end;
    *out = temp->data;

    list->end = temp->prev;

    if (list->end != NULL)
        list->end->next = NULL;
    else
        list->start = NULL; // lista ficou vazia

    free(temp);
    list->n--;

    return SUCCESS;
}

void popNode(Node *node, Data *out) {
    *out = node->data;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);
}

int removeAt(List_DL *list, const int index, Data *out) {
    if (isEmpty(list))
        return LIST_EMPTY;

    if (index < 0 || index >= list->n)
        return INVALID_INDEX;

    if (index == 0)
        return removeStart(list, out);

    if (index == list->n - 1)
        return removeEnd(list, out);

    Node* temp = list->start;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    popNode(temp, out);

    list->n--;
    return SUCCESS;
}

int removeByID(List_DL *list, const int id, Data *out) {
    if (isEmpty(list))
        return LIST_EMPTY;

    Node* temp = list->start;
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    if (temp == NULL)
        return ID_NOT_FOUND;

    if (temp == list->start)
        return removeStart(list, out);

    if (temp == list->end)
        return removeEnd(list, out);

    popNode(temp, out);

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

int getByID(const List_DL *list, const int id, Data *out) {
    if (isEmpty(list))
        return LIST_EMPTY;

    Node * temp = list->start;
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    if (temp == NULL)
        return ID_NOT_FOUND;

    *out = temp->data;
    return SUCCESS;
}

void printList(const List_DL *list) {
    printf("Lista (n = %d)\n", list->n);
    printf("Inicio: %p\n", (void*)list->start);
    printf("Fim:    %p\n\n", (void*)list->end);

    Node* temp = list->start;

    while (temp != NULL) {
        printf("Nodo: %p\n", (void*)temp);
        printf("  Data: { id: %d, qty: %.2f }\n\n",
               temp->data.id,
               temp->data.qty);

        temp = temp->next;
    }
}