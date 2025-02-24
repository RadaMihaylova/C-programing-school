/*Направете object-like макро, което да улеснява дефинирането на масив от 5 елемента, и което да се използва за да се принтират елементите от масива. 
Идеята е чрез макрото да контролирате размера на масива.*/

#include <stdio.h>

#define ARRAY_SIZE 5
#define DEFINE_ARRAY(name) int name[ARRAY_SIZE] = {0, 0, 0, 0, 0};
#define PRINT_ARRAY(name) \
for (int i =0;i < ARRAY_SIZE;i++){ \
    printf("%d\n", name[i]); \
} 
int main() {
    DEFINE_ARRAY(Array);
    for (int i = 0; i < ARRAY_SIZE; i++){
        Array[i] = i + 1;
    }
    PRINT_ARRAY(Array);

    return 0;
}


//Направете function-like макро, което да използва троичния(тернарния) оператор за сравнение за да намира по-големия от 2 елемента.

#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int x = 5, y = 10;
    int max_value = MAX(x, y);

    printf("По-голямото от %d и %d е %d\n", x, y, max_value);
    return 0;
}


//Направете макро, което да дефинира помощен инструмент за дебъгване, който да принтира името на променливата, нейната стойност файлът в който се използва и линията от код, 
//която принтира тази информация.

#include <stdio.h>

#define DEBUG_PRINT(var) printf("Debug: %s = %d, File: %s, Line: %d\n", #var, var, __FILE__, __LINE__)

int main() {
    int a = 5;
    float b = 3.14;
    
    DEBUG_PRINT(a);
    DEBUG_PRINT((int)b);  

    return 0;
}

/*Дефинирайте макро функция, която да се казва COMMAND да приема два аргумента NAME и TYPE и да създава идентификатор за командна функция от типа TYPE_NAME_command. 
Така например COMMAND(quit, internal) 
да създава идентификатор internal_quit_command. Направете макро функция която да се казва DEFINE_COMMAND, 
която да приема два аргумента NAME и TYPE и да използва макрото COMMAND за да създаде декларация на функция от типа “void TYPE_NAME_command(void)” така например 
DEFINE_COMMAND(quit, external) { … } 
трябва да създаде дефиниция на функция “void external_quit_command(void) {...}”.
Използвайте макрото за да дефинирате две функции, които да принтират просто съобщение на екрана. Извикайте тези функции в main.8*/

#define COMMAND(type, name) type##_##name##_command  
int int_a;
COMMAND(internal, quit)
internal_quit_command
fiosfpIAFP;
 