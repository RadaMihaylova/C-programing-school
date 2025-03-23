/*Да се направи програма - бележник на ученика за оценките му по програмиране, която има следните функционалности:
Когато програмата се стартира потребителя се подканя да се въведат колко на брой са съществуващите оценки по програмиране 
и след това той трябва да въведе тези оценки. За да реализирате тази функционалност използвайте динамично заделяне на памет за оценките.
Програмата трябва да предоставя след това меню с няколко опции:
            - Възможност за извеждане на средния успех на ученика            
            - Възможност за добавяне на нова оценка. За целта размерът на масивът, който съдържа оценките, трябва динамично да се разшири.
            - Възможност за изтриване на последната оценка. За целта размерът на масивът трябва динамично да се намали.
            - Изход от програма, при който динамично заделената памет се освобождава и програмата приключва.
Не забравяйте да проверите дали паметта е заделена коректно и ако не е да принтирате съобщение за грешка и да прекратите програмта. 
Програмата може да се прекрати с помощта на функцията exit(), която приема номера на грешката, с която искате програмата да приключи 
- например exit(1). Можете да си направите макро за да спестите писане на код. Също така погрижете се програмата да работи правилно, 
ако потребителя се опита да въведе 0 оценки или се опита да премахне всички налични оценки. Направете програмата така, 
че потребителя да не може да въведе отрицателно число за броя на оценките, 
и броят на оценките да не може да стане отрицателно число, по време на работата на програмата.*/


#include <stdio.h>
#include <stdlib.h>

#define ERROR(){ \
    printf("Error! No memory left\n"); \
    exit(1); \
}

void clearInputBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printMenu(){
    printf(
        "---Menu:---\n"
        "Choose option:\n"
        "1. Display the average grade\n"
        "2. Add new grade\n"
        "3. Erase last grade\n"
        "4. Exit\n"
        "Enter choice: "
    );
}

int main(){
    int numGrades;
    printf("Enter number of grades: ");
    if (scanf("%d", &numGrades) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (numGrades < 1) {
        printf("Number cannot be less than 1.\n");
        return 1;
    }
    int *grades = (int *)malloc(numGrades * sizeof(int));
    if (grades == NULL) {
        ERROR();
    }
    printf("Enter %d grades:\n", numGrades);
    for (int i = 0; i < numGrades; i++) {
        if (scanf("%d", &grades[i]) != 1) {
            printf("Invalid input for grade.\n");
            free(grades);
            return 1;
        }
    }
    // clearInputBuffer();
    int mustExit = 0;
    while (!mustExit) {
        printMenu();
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1: {
                if (numGrades==0){
                    printf("No grades\n");
                    continue;
                }
                int sum = 0;
                for (int i = 0; i < numGrades; i++) {
                    sum += grades[i];
                }
                float average = (float)sum / numGrades;
                printf("Average grade: %.2f\n", average);
                break;
            }
            case 2: {
                int newGrade;
                printf("Add new grade: ");
                if (scanf("%d", &newGrade) != 1) {
                    printf("Invalid input.\n");
                    clearInputBuffer();
                    continue;
                }
                // clearInputBuffer();
                int *temp = (int *)realloc(grades, (numGrades + 1) * sizeof(int));
                if (temp == NULL) {
                    printf("Error! No more memory in expansion!\n");
                    free(grades);
                    exit(EXIT_FAILURE);
                    // return EXIT_FAILURE;
                }
                grades = temp;
                grades[numGrades] = newGrade;
                numGrades++;
                printf("Grade added successfully.\n");
                break;
            }
            case 3: {
                if (numGrades == 0) {
                    printf("No grades to erase.\n");
                    continue;
                }
                if (numGrades == 1) {
                    free(grades);
                    grades = NULL;
                }
                else {
                    int *temp = (int *)realloc(grades, (numGrades - 1) * sizeof(int));
                    if (temp == NULL) {
                        printf("Error! No more memory in reduction.\n");
                        free(grades);
                        exit(EXIT_FAILURE);
                    }
                    grades = temp;
                }
                numGrades--;
                printf("Last grade was successfully erased.\n");
                break;
            }
            case 4:
                printf("Exiting program.\n");
                mustExit = 1;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    free(grades);
}


