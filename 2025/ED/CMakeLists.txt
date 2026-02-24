cmake_minimum_required(VERSION 4.0)
project(ED C)

set(CMAKE_C_STANDARD 23)

add_executable(ED main.c
        "semana3/4/ Cheque.c"
        "semana3/4/ Cheque.h"
        semana3/4/main.c
        stack/stack.c
        stack/stack.h
        queue/queue.c
        queue/queue.h
        fila/fila.c
        fila/fila.h
        fila/main.c
        List/Lista.c
        List/Lista.h
        List/main.c
        "stack/Linked/Pilha encadeada.c"
        "stack/Linked/Pilha encadeada.h"
        stack/Linked/main.c
        fila/linked/filaSE.c
        fila/linked/filaSE.h
        fila/linked/main.c
        List/Linked/Doble/dobleLinkedList.c
        List/Linked/Doble/dobleLinkedList.h)
