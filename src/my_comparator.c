#define _CRT_SECURE_NO_WARNINGS

#include "my_string.h"

int compare_str(void* data1, void* data2){
    char* str1 = (char*) data1;
    char* str2 = (char*) data2;

    return str_equal(str1, str2);
}

int compare_int(void* data1, void* data2){
    int* num1 = (int*) data1;
    int* num2 = (int*) data2;

    return *num1 == *num2;
}