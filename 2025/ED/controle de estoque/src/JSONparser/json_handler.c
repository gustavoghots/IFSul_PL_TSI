//
// Created by gusta on 02/12/2025.
//

#include "json_handler.h"
#include <stdio.h>
#include <string.h>
#include "../structs/list/list.h"

int json_writeInventory(const char *filename, const List *list) {
    FILE *file = fopen(filename, "w");
    if (!file) return FILE_ERROR;

    fprintf(file, "[\n");

    ListNode *temp = list->start;
    while (temp) {
        fprintf(file,
                "  { \"id\": %d, \"qty\": %.2f, \"description\": \"%s\" }%s\n",
                temp->data.id,
                temp->data.qty,
                temp->data.description,
                temp->next ? "," : ""
        );
        temp = temp->next;
    }

    fprintf(file, "]\n");
    fclose(file);
    return SUCCESS;
}


// --------------------------------------------------------------
// LER JSON E POPULAR LISTA (ESTOQUE)
// --------------------------------------------------------------
int json_readInventory(const char *filename, List *list) {
    FILE *file = fopen(filename, "r");
    if (!file) return FILE_ERROR;

    char line[256];
    Data item;
    int inObject = 0;
    int foundId = 0, foundQty = 0, foundDesc = 0;

    while (fgets(line, sizeof(line), file)) {

        // Detecta início do objeto
        if (strchr(line, '{')) {
            inObject = 1;
            foundId = foundQty = foundDesc = 0;
        }

        // Ler id
        if (inObject && strstr(line, "\"id\"")) {
            sscanf(strchr(line, ':') + 1, "%d", &item.id);
            foundId = 1;
        }

        // Ler qty
        if (inObject && strstr(line, "\"qty\"")) {
            sscanf(strchr(line, ':') + 1, "%lf", &item.qty);
            foundQty = 1;
        }

        // Ler description corretamente
        if (inObject && strstr(line, "\"description\"")) {
            char *key = strstr(line, "\"description\"");
            char *firstQuote = strchr(key, '"');      // "
            firstQuote = strchr(firstQuote + 1, '"'); // "
            firstQuote = strchr(firstQuote + 1, '"'); // início do valor

            if (firstQuote) {
                char *endQuote = strchr(firstQuote + 1, '"');
                if (endQuote) {
                    size_t len = endQuote - (firstQuote + 1);
                    if (len > sizeof(item.description) - 1)
                        len = sizeof(item.description) - 1;

                    strncpy(item.description, firstQuote + 1, len);
                    item.description[len] = '\0';

                    foundDesc = 1;
                }
            }
        }

        // Fechamento do objeto
        if (strchr(line, '}') && inObject) {
            if (foundId && foundQty && foundDesc) {
                ListNode *node = list_createNode(item);
                if (!node) {
                    fclose(file);
                    return MEMORY_FULL;
                }
                list_insertEnd(list, node);
            }
            inObject = 0;
        }
    }

    fclose(file);
    return SUCCESS;
}