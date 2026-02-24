//
// Created by gusta on 04/12/2025.
//

#ifndef CONTROLEDEESTOQUE_SYSTEMUTIL_H
#define CONTROLEDEESTOQUE_SYSTEMUTIL_H

#include "../structs/util.h"

void initSystem(List *stock, Queue *orders);

void saveStock(const List *stock);

void loadStock(List *stock);

#endif //CONTROLEDEESTOQUE_SYSTEMUTIL_H