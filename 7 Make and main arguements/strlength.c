#include <stdio.h>
#include <stdlib.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("How much it's used: %s <string>\n", argv[0]);
        return 1;
    }
    
    strlength(argv[1]);  
    return 0;
}