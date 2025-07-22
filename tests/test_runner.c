#include <stdio.h>

// strings
void test_str_length();
void test_str_equal();
void test_str_append();

// linked list
void test_insert_beginning();
void test_insert_end();
void test_create_list();
void test_delete_first_node();



int main() {
    // strings
    test_str_length();
    test_str_equal();
    test_str_append();

    // linked lists
    test_insert_beginning();
    test_insert_end();
    test_create_list();
    test_delete_first_node();

    printf("All tests passed.\n");
    return 0;
}
