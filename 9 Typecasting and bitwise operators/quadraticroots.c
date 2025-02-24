/*Направете файл “quadraticroots.h” в който се декларира структура “QuadraticRootsResult”, която държи резултат от намирането на корените на квадратно уравнение.
Структурата трябва да съдържа две член-променливи: x1 и x2 които да държат стойностите на корените на дадено квадратно уравнение. 
Към структурата трябва да има и флаг “norealroots”, който, ако има стойност “1”, означава, че уравнението няма реални корени. 
Декларирайте функция “findroots”, която да приема три параметара (a, b, c) и да намира корените на квадратното уравнение (ако има такива) или да обозначава, 
че уравнението няма реални корени. Функцията трябва да връща като резултат променлива от тип “QuadraticRootsResult”. 
Целта на задачата е да направите структурата и функцията да работят за всякакви данни, така че трябва да изберете подходящите типове за аргументите и член променливите. 
Направете файл “quadraticroots.c”, който да дефинира функцията “findroots”. 
За да намерите квадратния корен на дискриминантата използвайте функцията “sqrtl” декларирана в “math.h”. 
Не забравяйте да свържете библиотеката “libm” за можете да използвате функцията “sqrtl”.  
Направете файл “main.c”, който да демонстрира работата на функцията “findroots” извикана с аргументи от различни типове: един път с int аргументи, един път с float аргументи, 
един път с double аргументи. 
Направете Makefile, който да построява програмата.*/


#include <stdio.h>
#include "quadraticroots.h"

QuadraticRootsResult findroots(long double a, long double b, long double c) {
    QuadraticRootsResult result;
    long double discriminant = b * b - 4 * a * c;  

    if (discriminant < 0) {
        result.norealroots = 1;
    } else {
        result.norealroots = 0;
        result.x1 = (-b + sqrtl(discriminant)) / (2 * a);
        result.x2 = (-b - sqrtl(discriminant)) / (2 * a);
    }

    return result;
}
