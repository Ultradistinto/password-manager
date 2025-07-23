#include <stdio.h>

// strings
void test_str_length();
void test_str_equal();
void test_str_append();
void test_str_copy();
void test_str_splice();
void test_str_starts_with();

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
    test_str_copy();
    printf("Test de copy paso.\n");
    test_str_splice();
    printf("Test de splice paso.\n");
    test_str_starts_with();
    printf("Test de string paso.\n");


    // linked lists
    test_insert_beginning();
    test_insert_end();
    printf("Pasaron los tests de insert.\n");

    test_create_list();
    test_delete_first_node();
    printf("Test de linked list paso.\n");


    printf("All tests passed.\n");
    return 0;
}
