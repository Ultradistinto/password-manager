#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_linked_list.h"
#include "my_comparator.h"

void test_create_list() {
    Head* list = create_list();
    assert(list != NULL);
    assert(list->size == 0);
    assert(list->head == NULL);
    free(list);
}

void test_insert_beginning() {
    Head* list = create_list();
    int x = 42;
    insert_beginning(list, &x);
    assert(list->size == 1);
    assert(*(int*)list->head->data == 42);
    free(list->head);
    free(list);
}

void test_insert_end() {
    Head* list = create_list();
    int x = 42;
    insert_end(list, &x);
    assert(list->size == 1);
    assert(*(int*)list->head->data == 42);
    free(list->head);
    free(list);
}

void test_delete_first_node() {
    Head* list = create_list();
    
    int a = 10;
    int b = 20;
    int c = 30;

    insert_end(list, &a);
    insert_end(list, &b);
    insert_end(list, &c);

    assert(list->size == 3);
    assert(*(int*)list->head->data == 10);

    delete_first_node(list, &a, compare_int);
    assert(list->size == 2);
    assert(*(int*)list->head->data == 20);

    delete_first_node(list, &c, compare_int);
    assert(list->size == 1);
    assert(*(int*)list->head->data == 20);

    delete_first_node(list, &b, compare_int);
    assert(list->size == 0);
    assert(list->head == NULL);

    free(list);
}

