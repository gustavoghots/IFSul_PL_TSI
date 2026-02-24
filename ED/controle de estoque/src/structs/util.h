#ifndef UTIL_H
#define UTIL_H

#define SUCCESS 0
#define EMPTY 1
#define MEMORY_FULL 2

// ----------------------
// Item básico
// ----------------------
typedef struct Data{
    int id;
    double qty;
    char description[100];
} Data;


// ----------------------
// Lista duplamente ligada genérica de Item
// ----------------------
typedef struct ListNode {
    Data data;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

typedef struct List{
    ListNode* start;
    ListNode* end;
    int n;
} List;


// ----------------------
// Order (usa List)
// ----------------------
typedef struct Order{
    int id;
    char status[16];
    List items;    // lista com os itens da ordem
} Order;


// ----------------------
// Queue de Orders
// ----------------------
typedef struct QueueNode {
    Order order;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;


// ----------------------
// Stack de Orders
// ----------------------
typedef struct StackNode {
    Order order;
    struct StackNode* next;
} StackNode;

typedef struct Stack{
    StackNode* top;
    int size;
} Stack;

#endif

