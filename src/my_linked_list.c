#define _CRT_SECURE_NO_WARNINGS

#include "my_linked_list.h"
#include <stdlib.h>

Node* create_node(void* data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Head* create_list(){
    Head* new_list = (Head*)malloc(sizeof(Head));
    new_list->size = 0;
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

void insert_beginning(Head* list, void* new_data){
    Node* new_node = create_node(new_data);

    if(!list->head){
        list->tail = new_node;
    }
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void insert_end(Head* list, void* new_data){
    Node* new_node = create_node(new_data);
    new_node->next = NULL;

    if(list->size == 0){
        list->head = new_node;
        list->tail = new_node;
    }else{
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void delete_first_node(Head* list, void* node_delete, int (*compare)(const void*, const void*)){
    Node* prev = NULL;
    Node* iter = list->head;
    while(iter){
        if(compare(iter->data, node_delete)){
            if(prev){
                prev->next = iter->next;
            }
            else{
                list->head = iter->next;
            }
            free(iter);
            list->size--;
            return;
        }
        prev = iter;
        iter = iter->next;
    }
}

void destroy_node(Node* node){
    if (!node) return;
    if(node->next)
        destroy_node(node->next);
    free(node->data);
    free(node);
}
void destroy_list(Head* list){
    destroy_node(list->head);
    free(list);
}