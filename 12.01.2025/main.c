#include <stdio.h>
#include <stdlib.h>

#define EVEN 

int main(int argc, char *argv[]){
    for(int i = 0;i < argc;i++){
        int number = argv[i];
        #ifdef EVEN
        if(number % 2 == 0){
            printf("Chetno %d", number);
        } 
        #else 
        printf("Nechetno %d", number);
        #endif
    }
}