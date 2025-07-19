
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