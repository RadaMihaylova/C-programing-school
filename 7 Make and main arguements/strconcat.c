#include <stdio.h>
#include <stdlib.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    char str1[50];  
    snprintf(str1, sizeof(str1), "%s", argv[1]);  
    strconcat(str1, argv[2]);  

    printf("%s\n", str1);  
    return 0;
}