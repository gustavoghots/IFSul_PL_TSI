//
// Created by gusta on 03/12/2025.
//

#include <stdio.h>
#include "./stock/menuStock.h"
#include "./cart/menuCart.h"
#include "./order/orderMenu.h"
#include "../src/JSONparser/json_handler.h"
#include "../src/structs/util.h"
#include "../src/structs/queue/queue.h"

void mainMenu() {
    // ===============================
    // INITIALIZATION
    // ===============================
    List stock;
    Queue systemQueue;

    list_initList(&stock);
    queue_init(&systemQueue);

    // Load stock database
    printf("Loading database...\n");

    const int r = json_readInventory("../db/stock.json", &stock);
    if (r == SUCCESS) {
        printf("Stock loaded successfully!\n");
    } else {
        printf("Failed to load stock. Starting with empty list.\n");
    }

    int option;

    // ===============================
    // MENU PRINCIPAL
    // ===============================
    do {
        printf("\n=========================\n");
        printf("       MAIN MENU\n");
        printf("=========================\n");
        printf("1. Start new order\n");
        printf("2. Order queue\n");
        printf("3. Stock manager\n");
        printf("4. Reports (not implemented)\n");
        printf("0. Exit\n");
        printf("=========================\n");
        printf("Select an option: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                menuCart(&stock, &systemQueue);
                break;

            case 2:
                menuOrders(&stock, &systemQueue);
                break;

            case 3:
                menuStock(&stock);
                break;

            case 4:
                printf("\nReports not implemented yet.\n");
                break;

            case 0:
                printf("\nExiting system...\n\n");

                // Save stock before exiting
                json_writeInventory("../db/stock.json", &stock);
                printf("Stock saved.\n");

                return;

            default:
                printf("Invalid option.\n");
        }

    } while (1);
}

int main() {
    mainMenu();
    return 0;
}