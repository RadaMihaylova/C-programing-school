/*
--
Направете заглавен файл “person.h”, който да декларира структура “Person”,
която да съдържа информация, за името на човека (масив от 20 символа), неговото презиме (масив от 20 символа)
неговата фамилия (масив от 20 символа) и в коя година е роден (цяло число). 

Направете заглавен файл “schoolclass.h”, който да вмъква заглавния файл “person.h” и да декларира
структура “SchoolClass” (клас), която да съдържа масив от 26 ученика (от структурата Person),
паралелката на класа  (символ), номера на класа (цяло число) и класен ръководител (поле от тип Person).

Направете заглавен файл “schoolroom.h”, в който вмъкнете заглавния файл “person.h” и в който декларирайте
структруа “SchoolRoom”, която да съдържа номер на стаята (цяло число), и информация кои хора се намират
в тази стая в момента (масив от 50 елемента от тип Person).

Направете файл, който да се казва school.c и в него вмъкнете заглавните файлове “schoolclass.h” и ‘schoolroom.h” и
направете структура “School”, която да съдържа училищни класове (масив от тип SchoolClass с размер 20) и училищни стаи
(масив от тип SchoolRoom с размер 10). В файла school.c в main декларирайте променлива от тип school.
--
*/

#include <stdio.h>
#include "schoolclass.h"
#include "schoolroom.h"

typedef 
struct {
    SchoolClass classes[20];
    SchoolRoom rooms[10];
} 
School;


int main() {
    School mySchool;
    printf("");
    return 0;
}