//
// Created by gusta on 18/11/2025.
//

#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "../util.h"

ListNode *list_createNode(const Data data) {
    ListNode *newNode = malloc(sizeof(ListNode));
    if (!newNode)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int list_isEmpty(const List *list) {
    if (list->n == 0)
        return LIST_EMPTY;
    return SUCCESS;
}

void list_initList(List *list) {
    list->start = NULL;
    list->end = NULL;
    list->n = 0;
}

int list_size(const List *list) {
    return list->n;
}

ListNode *list_getNodeByID(const List *list, const int id) {
    if (list_isEmpty(list))
        return NULL;

    const ListNode *temp = list->start;
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    if (temp == NULL)
        return NULL;

    return (ListNode *) temp;
}

int list_insertStart(List *list, ListNode *node) {
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

int list_insertEnd(List *list, ListNode *node) {
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

int list_insert(List *list, const int index, const Data data) {
    if (index < 0 || index > list->n)
        return INVALID_INDEX;

    ListNode *newNode = list_createNode(data);
    if (newNode == NULL)
        return MEMORY_FULL;

    if (index == 0)
        return list_insertStart(list, newNode);

    if (index == list->n)
        return list_insertEnd(list, newNode);

    ListNode *temp = list->start;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;

    list->n++;

    return SUCCESS;
}

int list_insertAfter(List *list, const int id, const Data data) {
    // Lista vazia
    if (list->n == 0)
        return ID_NOT_FOUND;

    ListNode *temp = list->start;

    // Buscar pelo id
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    // Não encontrou
    if (temp == NULL)
        return ID_NOT_FOUND;

    // Criar novo
    ListNode *newNode = list_createNode(data);
    if (newNode == NULL)
        return MEMORY_FULL;

    newNode->data = data;

    if (temp->next == NULL)
        return list_insertEnd(list, newNode);

    // Insere depois temp
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    list->n++;
    return SUCCESS;
}

int list_removeStart(List *list, Data *out) {
    if (list_isEmpty(list))
        return LIST_EMPTY;

    ListNode *temp = list->start;
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

int list_removeEnd(List *list, Data *out) {
    if (list_isEmpty(list))
        return LIST_EMPTY;

    ListNode *temp = list->end;
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

void list_popNode(ListNode *node, Data *out) {
    *out = node->data;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);
}

int removeAt(List *list, const int index, Data *out) {
    if (list_isEmpty(list))
        return LIST_EMPTY;

    if (index < 0 || index >= list->n)
        return INVALID_INDEX;

    if (index == 0)
        return list_removeStart(list, out);

    if (index == list->n - 1)
        return list_removeEnd(list, out);

    ListNode *temp = list->start;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    list_popNode(temp, out);

    list->n--;
    return SUCCESS;
}

int list_removeByID(List *list, const int id, Data *out) {
    if (list_isEmpty(list))
        return LIST_EMPTY;

    ListNode *temp = list->start;
    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    if (temp == NULL)
        return ID_NOT_FOUND;

    if (temp == list->start)
        return list_removeStart(list, out);

    if (temp == list->end)
        return list_removeEnd(list, out);

    list_popNode(temp, out);

    list->n--;

    return SUCCESS;
}

int list_updateItemQty(const List *list, const int id, const float qtyDelta) {
    if (list_isEmpty(list))
        return LIST_EMPTY;

    ListNode *temp = list_getNodeByID(list, id);
    if (temp == NULL)
        return ID_NOT_FOUND;

    temp->data.qty += qtyDelta;
    return SUCCESS;
}

int get(const List *list, const int index, Data *out) {
    if (index < 0 || index >= list->n)
        return INVALID_INDEX;

    ListNode *temp;

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

int list_getByID(const List *list, const int id, Data *out) {
    if (list_isEmpty(list))
        return LIST_EMPTY;

    const ListNode *temp = list_getNodeByID(list, id);
    if (temp == NULL)
        return ID_NOT_FOUND;

    *out = temp->data;
    return SUCCESS;
}

void list_printList(const List *list) {
    printf("\n=====================\n");
    printf("   INVENTORY LIST\n");
    printf("=====================\n");
    printf("Total items: %d\n\n", list->n);

    if (list_isEmpty(list)) {
        printf("(empty list)\n\n");
        return;
    }

    ListNode *temp = list->start;

    while (temp != NULL) {
        printf("ID:   %d\n", temp->data.id);
        printf("QTY:  %.2f\n", temp->data.qty);
        printf("DESC: %s\n", temp->data.description);
        printf("---------------------\n");

        temp = temp->next;
    }
}