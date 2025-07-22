#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_string.h"

void test_str_length() {
    assert(str_length("") == 0);
    assert(str_length("hello") == 5);
    assert(str_length("abc") == 3);
}

void test_str_equal() {
    assert(str_equal("abc", "abc") == 1);
    assert(str_equal("abc", "def") == 0);
    assert(str_equal("abc", "abcd") == 0);
    assert(str_equal("", "") == 1);
}

void test_str_append() {
    char* result = str_append("gmail", "password123");
    assert(str_equal(result, "gmail:password123") == 1);
    free(result);

    result = str_append("", "123");
    assert(str_equal(result, ":123") == 1);
    free(result);

    result = str_append("service", "");
    assert(str_equal(result, "service:") == 1);
    free(result);
}
