/*Направете програма, която въвежда две променливи тип double от потребителя с помощта на scanf. 
Насочете два указателя към тях. И принтирайте адресите на указателите и стойностите на променливите, към които сочат.*/

#include <stdio.h>

int main() {
    double num1, num2;
    printf("Add stoinost: ");
    scanf("%lf", &num1);
    printf("Add stoinost: ");
    scanf("%lf", &num2);
    double *x1 = &num1;
    double *x2 = &num2;
    printf("Address of num1 is: %p\n", *x1);
    printf("Address of num2 is: %p\n", *x2);
    printf("\n");
    printf("Stoinost of num1 is: %lf\n", *x1);
    printf("Stoinost of num2 is: %lf\n", *x2);
    
}