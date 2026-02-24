cmake_minimum_required(VERSION 3.26)
project(ControleDeEstoque C)

set(CMAKE_C_STANDARD 11)


add_executable(ControleDeEstoque
        controller/main.c
        controller/stock/menuStock.c
        controller/cart/menuCart.c
        controller/order/orderMenu.c
        src/structs/list/list.c
        src/structs/queue/queue.c
        src/structs/stack/stack.c
        src/JSONparser/json_handler.c
)
