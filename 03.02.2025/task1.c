/*Направете програма, която приема числа от командния ред и използва побитови операции за управление на осветлението в 8 стаи. 
Числата 1-8 включват/изключват осветлението в съответната стая. 
Условната компилация се използва за проследяване на евентуални грешки (DEBUG_MODE).*/

// С DEBUG_MODE макрос

#include <stdio.h>
#include <stdlib.h>

#define DEBUG

int main(int argc, char *argv[]){
    char lights = 0;
    if(argc > 1){
        int a = atoi(argv[1]);
        //0000 0000
        //0000 1000
        //0000 0001
        if(a < 1 || a > 8){
            printf("Please enter a number between 1 and 8.\n");
            return 1;
        }
        lights = lights | 1 << a - 1 ;
        #ifdef DEBUG 
        printf("Debug %d", lights, a);
        #endif
        printf("%d", lights);
        //0000 0010 = light 2
        //0000 1000 = light 4
        //0000 1010
    }
    return 0;
}