/*Направете програма, която да принтира таблица с информация за всеки един целочислен тип в C. 
Всеки ред от таблицата трябва да съдържа името на типа, формата, чрез който се принтира, колко байта заема, 
максималната стойност на знаковата (signed) версията на типа, минималната стойност на знаковата (signed) стойност на типа  
и формата на безнаковата версия и максималната стойност на безнаковата версия на типа (unsigned). 
Можете да използвате макро за да съкратите работата по принтирането на данните.*/


#include <stdio.h>
#include <limits.h>  


#define PRINT_INT_INFO(type) \
    printf("%-10s %-10s %-10zu %-20lld %-20lld %-10s %-20llu\n", \
           #type, #type, sizeof(type), (long long)SINT_MIN(type), \
           (long long)SINT_MAX(type), #type " unsigned", \
           (unsigned long long)UINT_MAX(type));

#define SINT_MIN(type) ((type)-1 << (sizeof(type) * 8 - 1))  
#define SINT_MAX(type) ((type)((1ULL << (sizeof(type) * 8 - 1)) - 1))  
#define UINT_MAX(type) ((type)(-1))  



int main() {
    printf("%-10s %-10s %-10s %-20s %-20s %-10s %-20s\n", 
           "Type", "Format", "Size", "Signed Min", "Signed Max", "Unsigned", "Unsigned Max");
    PRINT_INT_INFO(char);
    PRINT_INT_INFO(short);
    PRINT_INT_INFO(int);
    PRINT_INT_INFO(long);
    PRINT_INT_INFO(long long);
    return 0;
}
