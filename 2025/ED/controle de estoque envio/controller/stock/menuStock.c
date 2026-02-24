//
// Created by gusta on 05/12/2025.
//

#include "menuStock.h"

#include <stdio.h>
#include <string.h>

#include "../../src/JSONparser/json_handler.h"
#include "../../src/structs/list/list.h"
#include "../../src/structs/util.h"

void menuStock(List *stock) {
    int option;

    do {
        printf("\n=========================\n");
        printf("     STOCK MANAGER\n");
        printf("=========================\n");
        printf("1. Load inventory from file\n");
        printf("2. Save inventory to file\n");
        printf("3. Add item\n");
        printf("4. Remove item\n");
        printf("5. Update item quantity\n");
        printf("6. Search item by ID\n");
        printf("7. Print inventory\n");
        printf("0. Return\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 1) {
            list_initList(stock); // limpar lista antes de carregar
            const int r = json_readInventory("../db/stock.json", stock);
            if (r == SUCCESS) printf("Inventory loaded!\n");
            else printf("Error loading file.\n");
        } else if (option == 2) {
            const int r = json_writeInventory("../db/stock.json", stock);
            if (r == SUCCESS) printf("Inventory saved!\n");
            else printf("Error saving file.\n");
        } else if (option == 3) {
            Data item;
            printf("New item ID: ");
            scanf("%d", &item.id);

            printf("Quantity: ");
            scanf("%lf", &item.qty);

            printf("Description: ");
            getchar(); // consumir \n
            fgets(item.description, sizeof(item.description), stdin);

            // remover \n
            item.description[strcspn(item.description, "\n")] = '\0';

            ListNode *node = list_createNode(item);
            if (!node) {
                printf("Memory error.\n");
                continue;
            }

            list_insertEnd(stock, node);
            printf("Item added!\n");
        } else if (option == 4) {
            int id;
            Data removed;

            printf("Enter ID to remove: ");
            scanf("%d", &id);

            int r = list_removeByID(stock, id, &removed);
            if (r == SUCCESS)
                printf("Item removed: %s\n", removed.description);
            else
                printf("Item not found.\n");
        } else if (option == 5) {
            int id;
            float delta;

            printf("Enter ID: ");
            scanf("%d", &id);

            printf("Quantity change (use negative to subtract): ");
            scanf("%f", &delta);

            int r = list_updateItemQty(stock, id, delta);
            if (r == SUCCESS)
                printf("Quantity updated!\n");
            else
                printf("Item not found.\n");
        } else if (option == 6) {
            int id;
            Data result;

            printf("Enter ID: ");
            scanf("%d", &id);

            int r = list_getByID(stock, id, &result);
            if (r == SUCCESS)
                printf("Found: [%d] %.2lf - %s\n", result.id, result.qty, result.description);
            else
                printf("Item not found.\n");
        } else if (option == 7) {
            list_printList(stock);
        }
    } while (option != 0);
}