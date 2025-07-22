#include <stdio.h>

// Declare test functions from test_my_string.c
void test_str_length();
void test_str_equal();
void test_str_append();

// Declare test functions from test_my_linked_list.c
void test_insert_beginning();
void test_insert_end();
void test_create_list();



int main() {
    // strings
    test_str_length();
    test_str_equal();
    test_str_append();

    // linked lists
    test_insert_beginning();
    test_insert_end();
    test_create_list();

    printf("All tests passed.\n");
    return 0;
}
