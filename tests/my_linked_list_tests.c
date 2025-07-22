#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_linked_list.h"

void test_create_list() {
    Head* list = create_list();
    assert(list != NULL);
    assert(list->size == 0);
    assert(list->next == NULL);
    free(list);
}

void test_insert_beginning() {
    Head* list = create_list();
    int x = 42;
    insert_beginning(list, &x);
    assert(list->size == 1);
    assert(*(int*)list->next->data == 42);
    free(list->next);
    free(list);
}

void test_insert_end() {
    Head* list = create_list();
    int x = 42;
    insert_end(list, &x);
    assert(list->size == 1);
    assert(*(int*)list->next->data == 42);
    free(list->next);
    free(list);
}
