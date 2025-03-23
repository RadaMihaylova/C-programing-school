/*Направете функция, която да намира дължината на символен низ, използвайки адресна аритметика за обхождане на масива.*/

#include <stdio.h>


int length(const char *str){
    const char * end = str;
    while(*end) end++;
    return end - str;
}

int main(){
    const char *a = "abcdefg";
    printf("Length: %d\n", length(a));
    return 0;
}