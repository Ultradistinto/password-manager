#ifndef MY_TXT_H
#define MY_TXT_H

#include "my_linked_list.h" 

int txt_add(char* text);
Head* txt_get_words(FILE* file);
char* txt_get_full_text(char* original_file);
void txt_overwrite(Head* list, char* filename);
update_service_password(Head* list, char* service, char* password);
void setup_txt();

#endif