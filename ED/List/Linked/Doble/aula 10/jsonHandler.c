//
// Created by gusta on 23/11/2025.
//

//
// Created by AI Assistant on 23/11/2025.
//

#include "jsonHandler.h"
#include <stdio.h>
#include <string.h>

int writeArrayToJSON(const char* filename, const List_DL* list) {
    FILE* file = fopen(filename, "w");
    if (!file) return FILE_ERROR;

    fprintf(file, "[\n");

    Node* temp = list->start;
    while (temp) {
        fprintf(file,
            "  { \"id\": %d, \"qty\": %.2f }%s\n",
            temp->data.id,
            temp->data.qty,
            temp->next ? "," : ""
        );
        temp = temp->next;
    }

    fprintf(file, "]\n");
    fclose(file);
    return SUCCESS;
}


// Read array of Data entries from JSON file and populate list
int readArrayFromJSON(const char* filename, List_DL* list) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading\n", filename);
        return -1;
    }

    char line[256];
    Data currentData;
    int id = 0;
    double qty = 0.0;
    int foundId = 0, foundQty = 0;
    int inObject = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if we're entering an object
        if (strchr(line, '{') != NULL) {
            inObject = 1;
            foundId = 0;
            foundQty = 0;
        }

        // Parse id
        if (inObject && strstr(line, "\"id\"") != NULL) {
            char* colonPos = strchr(line, ':');
            if (colonPos != NULL) {
                sscanf(colonPos + 1, "%d", &id);
                foundId = 1;
            }
        }

        // Parse qty
        if (inObject && strstr(line, "\"qty\"") != NULL) {
            char* colonPos = strchr(line, ':');
            if (colonPos != NULL) {
                sscanf(colonPos + 1, "%lf", &qty);
                foundQty = 1;
            }
        }

        // Check if we're closing an object
        if (strchr(line, '}') != NULL && inObject) {
            if (foundId && foundQty) {
                currentData.id = id;
                currentData.qty = qty;

                Node* newNode = createNode(currentData);
                if (newNode != NULL) {
                    insertEnd(list, newNode);
                } else {
                    fclose(file);
                    return MEMORY_FULL;
                }
            }
            inObject = 0;
        }
    }

    fclose(file);
    return SUCCESS;
}