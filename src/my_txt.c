#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <my_linked_list.h>
#include "my_string.h"



int txt_add(char* text){
    printf("DEBUG: txt_add called with: %s\n", text);
    FILE* file = fopen("passwords.txt", "a");
    fprintf(file, "%s\n", text);

    fclose(file);
    return 0;
}

char* txt_search(char* text, char* ocurrence){
    return NULL;
}


Head* txt_get_words(FILE* file){
    Head* list_words = create_list();


    char word[256];
    while (fscanf(file, "%255s", word) == 1) {
        char* word_copy = malloc(str_length(word) + 1);
        str_copy(word_copy, word);
        insert_end(list_words, word_copy);
    }

    return list_words;
}