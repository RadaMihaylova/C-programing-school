/*Да се направи програма дневник на клас, която да пази списък с предмети, списък с ученици и годишната оценка, 
която всеки ученик има по даден предмет. 
Броят на предметите и техните имена се въвеждат в началото на програмата. След това на потребителя се показва меню с три опции: 
въвеждане на ученик, принтиране на дневника и изход от програмата. За целта:
При стартиране на програмата потребителя се подканва да въведе брой на предмети и техните имена. 
Броят на предметите трябва да е положително число различно от нула. След това се въвежда името на всеки един предмет, 
който може да е с различна дължина (максимум 15 символа). 
За да го реализирате това трябва да заделите памет за масив от символни низове и да запишете предметите в него.
При въвеждане на нов ученик, неговото име се въвежда от потребителя (то може да е с размер максимум 15 символа). 
Имената на учениците трябва да се пазят в динамичен масив, който се разширява всеки път, когато искаме да въведем нов ученик. 
След въвеждането на името се подканя да се въведе годишна оценка, за всеки един от предметите, 
като се принтира името на предмета и възможност за въвеждане на оценка. Оценките трябва да се пазят в двумерен масив, 
който има толкова редове, колкото са броят на учениците, и толкова колони, колкото са броят на предметите. 
Масивът трябва да се заделя динамично и да се разширява, всеки път, когато се въведе нов ученик.
При принтирането на оценките като първи ред трябва да се принтират имената на предметите 
(в началото с празно пространство от 15 символа за да се подравнят спрямо имената на учениците). 
и След това трябва да се изведе на информацията за учениците - по ред за всеки ученик (неговото име и оценки, по съответните предмети). 
Информацията трябва да е подредена като таблица.
При изход, трябва да се освобождава паметта за всички динамично заделени масиви. 
               
Не забравяйте да махнете новия ред при въвеждането на име. 
За целта можете да си направите функция, която да прочита символен низ, с големина до 15 символа и да премахне, 
новия ред от него, преди да върне указател към масива.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 16 

void readline(char *line, int size){
    fgets(line, size, stdin);
    char * p = strchr(line, '\n');
    if (p) *p = 0;
}

void printMenu(){
    printf(
        "---Menu---\n"
        "1. Add new student\n"
        "2. Print grades\n"
        "3. Exit\n"
    );
}

int main(){
    printf("How many subjects: ");
    int subjectCount;
    scanf("%d", &subjectCount);
    while(getchar()!='\n');
    if (subjectCount < 1){
        fprintf(stderr, "The subjects must be positive number.\n");
        return 1;
    }
    char **subjects = (char **)malloc(subjectCount * sizeof(char*));
    if (subjects==NULL){
        fprintf(stderr, "Malloc error\n");
        return 1;
    }
    for(int i = 0; i < subjectCount; i++){
        printf("Subject %d: ", i+1);
        subjects[i] = (char*)malloc(NAME_SIZE * sizeof(char));
        if (subjects[i]==NULL){
            fprintf(stderr, "Malloc error\n");
            return 1;
        }
        readline(subjects[i], NAME_SIZE);
    }
    char **students = NULL;
    int **grades = NULL;
    int studentCount = 0;
    while(1){
        printMenu();
        int option;
        scanf("%d", &option);
        while(getchar()!='\n');
        switch(option){
            case 1:
                students = realloc(students, (studentCount+1) * sizeof(char*));
                if (students==NULL){
                    fprintf(stderr, "Realloc error\n");
                    return 1;
                }
                students[studentCount] = (char*)malloc(NAME_SIZE * sizeof(char));
                if (students[studentCount]==NULL){
                    fprintf(stderr, "Malloc error\n");
                    return 1;
                }
                printf("Student name: ");
                readline(students[studentCount], NAME_SIZE);
                grades = realloc(grades, (studentCount+1) * sizeof(int*));
                if (grades==NULL){
                    fprintf(stderr, "Realloc error\n");
                    return 1;
                }
                grades[studentCount] = (int*)malloc(subjectCount * sizeof(int));
                if (grades[studentCount]==NULL){
                    fprintf(stderr, "Malloc error\n");
                    return 1;
                }
                for(int i = 0; i < subjectCount; i++){
                    printf("%s: ", subjects[i]);
                    scanf("%d", &grades[studentCount][i]);
                }
                studentCount++;
                break;
            case 2:
                printf("%-15s", "");
                for(int i = 0; i < subjectCount; i++){
                    printf("%-15s", subjects[i]);
                }
                printf("\n");
                for(int i = 0; i < studentCount; i++){
                    printf("%-15s", students[i]);
                    for(int j = 0; j < subjectCount; j++){
                        printf("%-15d", grades[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("End");
                goto END;
        }
    }
    END:
    for(int i = 0; i < studentCount; i++){
        free(grades[i]);
    }
    free(grades);
    for(int i = 0; i < studentCount; i++){
        free(students[i]);
    }
    free(students);
    for(int i = 0; i < subjectCount; i++){
        free(subjects[i]);
    }
    free(subjects);
}