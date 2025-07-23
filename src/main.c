#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "../include/my_string.h"
#include "../include/my_txt.h"
#include <my_linked_list.h>


void add_password(){
    char* service = malloc(50 * sizeof(char));
    char* password = malloc(50 * sizeof(char));
    char* password2 = malloc(50 * sizeof(char));

    printf("\n=== Add Password ===\n");
    printf("Enter Website/Service: ");
    scanf("%49s", service);
    printf("\nEnter Password: ");
    scanf("%49s", password);
    printf("\nRepeat Password: ");
    scanf("%49s", password2);

    while(!str_equal(password, password2)){
        printf("\nEnter Password: ");
        scanf("%49s", password);
        printf("\nRepeat Password: ");
        scanf("%49s", password2);
    }

    setup_txt();
    Head* list = txt_get_words(fopen("passwords.txt", "r"));


    if (!update_service_password(list, service, password)) {
        char* result = str_append(service, password);
        insert_end(list, result);
    }

    txt_overwrite(list, "passwords.txt");

    free(password);
    free(password2);
    free(service);

    destroy_list(list);
}

void view_password(){
    
}



int main() {
    printf("=== Password Manager ===\n");
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Exit\n");
    printf("Choose option: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            add_password();
            break;
        case 2:
            view_password();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}