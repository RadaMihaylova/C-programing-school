/*Направете програма, която да принтира на екрана помощно меню, което да дава информация за това как се работи с приложението, което ще реализирате с това домашно. 
Когато програмата се стартира трябва на екрана да се покажат имената на три функции “strlength, strconcat и strcompare и срещу всяка една от тях информация какво прави тя. 
Първата функция strlength трябва да намира дължината на символен низ. Втората функция strconcat трябва да обединява два символни низа. 
Третата функция strcompare трябва да сравнява два символни низа. Направете Makefile който да се състои от две цели: “help.out” (под windows help.exe”), 
която да построява приложението и от целта “clean”, която да изчиства файловете получени по време на компилация на приложението.*/


#include <stdio.h>
#include <string.h>


void help() {
    printf("Help menu for working with the application::\n");
    printf("1. strlength - Finds the length of a character string.\n");
    printf("2. strconcat - Merges two character strings.\n");
    printf("3. strcompare – Compares two character strings.\n");
}

int main() {
    print_help();
    return 0;
}