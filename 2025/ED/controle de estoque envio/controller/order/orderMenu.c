//
// Created by gusta on 05/12/2025.
//

#include "orderMenu.h"

#include <stdio.h>

#include "../cart/menuCart.h"
#include "../../src/structs/queue/queue.h"
#include "../../src/structs/list/list.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void queue_print(const Queue *q) {
    printf("Queue size: %d\n", queue_size(q));

    QueueNode *node = q->front;
    while (node != NULL) {
        printf("Order ID: %d | Status: %s | Items: %d\n",
               node->order.id,
               node->order.status,
               node->order.items.n);
        node = node->next;
    }
}

void inspectOrder(const Queue *q) {
    if (queue_isEmpty(q)) {
        printf("Order queue is empty.\n");
        return;
    }

    int targetId;
    printf("Enter the order ID to inspect: ");
    scanf("%d", &targetId);
    clearInputBuffer();

    QueueNode *node = q->front;

    while (node != NULL) {
        if (node->order.id == targetId) {
            printf("\n=== ORDER DETAILS ===\n");
            printf("ID: %d\n", node->order.id);
            printf("Status: %s\n", node->order.status);
            printf("Items:\n");
            list_printList(&node->order.items);
            return;
        }
        node = node->next;
    }

    printf("Order with ID %d not found.\n", targetId);
}

void finishOrder(Queue *q) {
    if (queue_isEmpty(q)) {
        printf("Order queue is empty. Nothing to finish.\n");
        return;
    }

    Order done;
    queue_dequeue(q, &done);

    printf("Order %d finished!\n", done.id);
    // opcional: free da lista interna
}

void cancelOrder(Queue *q) {
    if (queue_isEmpty(q)) {
        printf("Order queue is empty. Nothing to cancel.\n");
        return;
    }

    Order cancelled;
    queue_dequeue(q, &cancelled);

    printf("Order %d has been cancelled.\n", cancelled.id);
}

void menuOrders(const List *stock, Queue *systemQueue) {
    int option = -1;

    while (option != 0) {
        printf("\n=== ORDER MANAGEMENT ===\n");
        printf("1. Create new order\n");
        printf("2. View order queue\n");
        printf("3. Inspect an order\n");
        printf("4. Finish next order\n");
        printf("5. Cancel next order\n");
        printf("0. Back to main menu\n");
        printf("Select an option: ");

        scanf("%d", &option);
        clearInputBuffer();

        switch (option) {

            case 1:
                printf("\n--- Creating a new order ---\n");
                menuCart(stock, systemQueue);
                break;

            case 2:
                printf("\n--- Order Queue ---\n");
                queue_print(systemQueue);
                break;

            case 3:
                inspectOrder(systemQueue);
                break;

            case 4:
                finishOrder(systemQueue);
                break;

            case 5:
                cancelOrder(systemQueue);
                break;

            case 0:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}