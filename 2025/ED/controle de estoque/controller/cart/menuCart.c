//
// Created by gusta on 05/12/2025.
//

#include "menuCart.h"

#include <stdio.h>
#include <string.h>

// ==========================
// HELPERS
// ==========================

// Validar se item existe no estoque
int findItemInStock(const List *stock, int id, Data *out) {
    return list_getByID(stock, id, out);
}

// Verificar se quantidade pedida está disponível
int validateQty(const Data *stockItem, double qty) {
    return (qty <= stockItem->qty);
}

// Adicionar item no carrinho
int cart_addItem(List *cart, const List *stock) {
    int id;
    double qty;

    printf("Enter item ID: ");
    scanf("%d", &id);

    Data stockItem;
    if (findItemInStock(stock, id, &stockItem) != SUCCESS) {
        printf("❌ Item not found in stock!\n");
        return ID_NOT_FOUND;
    }

    printf("Enter quantity: ");
    scanf("%lf", &qty);

    if (!validateQty(&stockItem, qty)) {
        printf("❌ Not enough stock available!\n");
        return INVALID_INDEX;
    }

    Data newItem = {
        .id = id,
        .qty = qty
    };
    strncpy(newItem.description, stockItem.description, sizeof(newItem.description));

    ListNode *node = list_createNode(newItem);
    if (!node) return MEMORY_FULL;

    list_insertEnd(cart, node);
    printf("✔ Item added!\n");
    return SUCCESS;
}

// Remover item do carrinho
int cart_removeItem(List *cart) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    Data removed;
    int r = list_removeByID(cart, id, &removed);

    if (r == SUCCESS) {
        printf("✔ Item removed!\n");
    } else {
        printf("❌ Item not found in cart.\n");
    }
    return r;
}

// Alterar quantidade
int cart_updateQty(const List *cart, const List *stock) {
    int id;
    double qty;

    printf("Enter item ID: ");
    scanf("%d", &id);

    Data *cartItemPtr = NULL;
    ListNode *node = list_getNodeByID(cart, id);
    if (!node) {
        printf("❌ Item not in cart.\n");
        return ID_NOT_FOUND;
    }

    cartItemPtr = &node->data;

    printf("New quantity: ");
    scanf("%lf", &qty);

    Data stockItem;
    if (findItemInStock(stock, id, &stockItem) != SUCCESS) {
        printf("❌ Item not found in stock (this shouldn't happen!)\n");
        return ID_NOT_FOUND;
    }

    if (!validateQty(&stockItem, qty)) {
        printf("❌ Not enough stock.\n");
        return INVALID_INDEX;
    }

    cartItemPtr->qty = qty;
    printf("✔ Quantity updated!\n");
    return SUCCESS;
}

// Finalizar compra → enviar Order para Queue
int cart_checkout(List *cart, Queue *q) {
    if (list_isEmpty(cart)) {
        printf("❌ Cart is empty.\n");
        return EMPTY;
    }

    static int nextOrderID = 1;

    Order order;
    order.id = nextOrderID++;
    strcpy(order.status, "pending");

    list_initList(&order.items);

    // copiar itens do carrinho para order
    ListNode *temp = cart->start;
    while (temp) {
        ListNode *node = list_createNode(temp->data);
        list_insertEnd(&order.items, node);
        temp = temp->next;
    }

    queue_enqueue(q, order);

    printf("\n============================\n");
    printf("   ORDER #%d ADDED TO QUEUE\n", order.id);
    printf("============================\n\n");

    // limpar carrinho
    list_initList(cart);

    return SUCCESS;
}

// ==========================
// MAIN CART MENU
// ==========================

void menuCart(const List *stock, Queue *systemQueue) {
    List cart;
    list_initList(&cart);

    int option;

    do {
        printf("\n=========================\n");
        printf("       CART MANAGER\n");
        printf("=========================\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update item quantity\n");
        printf("4. View cart\n");
        printf("5. Finalize order\n");
        printf("0. Return\n");
        printf("=========================\n");
        printf("Select an option: ");

        scanf("%d", &option);

        switch (option) {
            case 1: cart_addItem(&cart, stock); break;
            case 2: cart_removeItem(&cart); break;
            case 3: cart_updateQty(&cart, stock); break;
            case 4: list_printList(&cart); break;
            case 5: cart_checkout(&cart, systemQueue); break;

            case 0:
                printf("Returning...\n");
                return;

            default:
                printf("Invalid option!\n");
        }
    } while (1);
}
