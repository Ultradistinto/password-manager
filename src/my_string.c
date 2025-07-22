#define _CRT_SECURE_NO_WARNINGS

#include <stddef.h>
#include <stdlib.h>
#include <stdlib.h> 
#include "my_linked_list.h"

int str_length(char* str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int str_equal(char* str1, char* str2){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return 0;
        }
        else{
            i++;
        }
    }
    if(str1[i] == '\0' && str2[i] == '\0'){
        return 1;
    }
    return 0;
}

char* str_append(char* service, char* password){

    int i = 0;
    int j = 0;
    int service_length = str_length(service);
    int password_length = str_length(password);

    char* result = malloc(service_length + password_length + 2);

    while(service[i] != '\0'){
        result[i] = service[i];
        i++;
    }
    result[i] = ':';
    i++;
    while(password[j] != '\0'){
        result[i] = password[j];
        i++;
        j++;
    }
    result[i] = '\0';
    
    return result;
}

void str_copy(char* original, char* copia){
    
    int indice = 0;
    int largo_original = str_length(original);
    while(indice < largo_original){
        copia[indice] = original[indice];

        indice++;
    }
    copia[indice] = '\0';
}

Head* str_splice(char divider, char* text){
    Head* list = create_list();

    int i = 0;
    int length = str_length(text);

    while(i < length){

        while (i < length && text[i] == divider) i++;
        if (i >= length) break;

        int word_start = i;
        int word_length = 0;

        while(i < length && text[i] != divider){
            word_length++;
            i++;
        }

        char* word = malloc(word_length + 1);
        for(int j = 0; j < word_length; j++){
            word[j] = text[word_start + j];
        }
        word[word_length] = '\0';

        insert_end(list, word);
    }
    return list;
}