#include <stdio.h>
#include <stdlib.h>



int txt_add(char* text){
    printf("DEBUG: txt_add called with: %s\n", text);
    FILE* file = fopen("passwords.txt", "a");
    fprintf(file, "%s\n", text);

    fclose(file);
    return 0;
}