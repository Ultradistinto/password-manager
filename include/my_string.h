#ifndef MY_STRING_H
#define MY_STRING_H

#include "my_linked_list.h" 

int str_length(char* str);
int str_equal(char* str1, char* str2);
char* str_append(char* service, char* password);
void str_copy(char* str1, char* str2);
Head* str_splice(char divider, char* text);
int str_starts_with(char* string, char* start);

#endif