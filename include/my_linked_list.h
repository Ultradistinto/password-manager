#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H


typedef struct Node {
    void* data;
    struct Node* next;
} Node;
typedef struct Head{
    Node* tail;
    Node* head;
    int size;
} Head;  

Head* create_list();
Node* create_node(void* data);
void insert_beginning(Head* list, void* data);
void insert_end(Head* list, void* data);
void delete_first_node(Head* list, void* data, int (*compare)(const void*, const void*));
void delete_all_node(Head* list, void* data);
void print_list(Head* list);
void delete_list(Head* list);  


#endif