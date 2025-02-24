#include <stdio.h>
#include <string.h>
#include "my_strings.h"

int strlength(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void strconcat(char *str1, const char *str2) {
    while (*str1) {  
        str1++;
    }
    while (*str2) {  
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0'; 
}

int strcompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 < *str2) {
            return -1;  
        }
        if (*str1 > *str2) {
            return 1;   
        }
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0') {
        return 0;  
    }
    if (*str1 == '\0') {
        return -1;  
    }
    return 1;  
}