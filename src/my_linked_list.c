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
    new_list->next = NULL;

    return new_list;
}

void insert_beginning(Head* list, void* new_data){
    Node* new_node = create_node(new_data);
    
    new_node->next = list->next;
    list->next = new_node;
    list->size++;
}

void insert_end(Head* list, void* new_data){

    Node* aux = list->next;
    if(!aux){
        insert_beginning(list, new_data);
    }else{
        while (aux->next){
            aux = aux->next;
        }
        Node* new_node = create_node(new_data);
        aux->next = new_node;
        list->size++;

    }
}

void delete_first_node(Head* list, void* node_delete, int (*compare)(const void*, const void*)){
    Node* prev = list;
    Node* iter = prev->next;
    while(iter){
        if(compare(iter->data, node_delete)){
            prev->next = iter->next;
            free(iter);
            list->size--;
            return;
        }
        prev = iter;
        iter = iter->next;
    }
}