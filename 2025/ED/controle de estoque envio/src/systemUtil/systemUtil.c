//
// Created by gusta on 02/12/2025.
//
#include "systemUtil.h"

#include "../JSONparser/json_handler.h"
#include "../structs/util.h"
#include "../structs/list/list.h"
#include "../structs/queue/queue.h"

void initSystem(List *stock, Queue *orders) {
    list_initList(stock);
    queue_init(orders);
}

void saveStock(const List *stock) {
    json_writeInventory("../../db/stock.json", stock);
}

void loadStock(List *stock) {
    json_readInventory("../../db/stock.json", stock);
}