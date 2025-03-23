/*Използвайте функцията strchr за да премахнете новия ред от символни низове въведени с помощта на 
fgets(https://en.cppreference.com/w/c/io/fgets) функцията. strchr е функция която приема символен низ 
и символ и връща указател към клетката от символния низ, 
която съдържа търсения символ или NULL указател ако символът не се намери (https://en.cppreference.com/w/c/string/byte/strchr). */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    char arr[120];
    printf("Сложете низ: ");
    fgets(arr, sizeof(arr), stdin);
    char *s = strchr(arr, '\n');
    if (s) {
        *s = '\0';
    }
    printf("Нов низ: ", arr);
    return 0;
}