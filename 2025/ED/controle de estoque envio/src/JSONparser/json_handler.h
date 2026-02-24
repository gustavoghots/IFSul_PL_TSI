//
// Created by gusta on 02/12/2025.
//

#ifndef CONTROLE_DE_ESTOQUE_JSON_HANDLER_H
#define CONTROLE_DE_ESTOQUE_JSON_HANDLER_H

#include "../structs/util.h"

#define FILE_ERROR -1

int json_writeInventory(const char *filename, const List *list);

int json_readInventory(const char *filename, List *list);

#endif //CONTROLE_DE_ESTOQUE_JSON_HANDLER_H
