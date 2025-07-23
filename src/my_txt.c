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

Head* txt_get_words(FILE* file){
    Head* list_words = create_list();

    char word[256];
    while (fscanf(file, "%255s", word) == 1) {
        char* word_copy = malloc(str_length(word) + 1);
        str_copy(word, word_copy);
        insert_end(list_words, word_copy);
    }

    return list_words;
}


char* txt_get_full_text(char* original_file){
    FILE* file = fopen(original_file, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char* buffer = malloc(length + 1);
    if(!buffer){
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}

void txt_overwrite(Head* list, char* filename){
    FILE* file = fopen(filename, "w");
    if(!file) return;

    Node* current = list->head;
    while(current){
        fprintf(file, "%s\n", (char*)current->data);
        current = current->next;
    }
    fclose(file);
}

int update_service_password(Head* list, char* service, char* password){
    Node* current = list->head;
    int updated = 0;
    while(current){
        if(str_starts_with(current->data, service)){
            free(current->data);
            current->data = str_append(service, password);
            return ++updated;
        }
        current = current->next;
    }
    return updated;
}

void setup_txt(){
    FILE* file = fopen("passwords.txt", "r");
    if (!file) {
        file = fopen("passwords.txt", "w");
        if (!file) {
            printf("Error creando archivo.\n");
            return;
        }
        fclose(file);
        return;
    }
    fclose(file);
}