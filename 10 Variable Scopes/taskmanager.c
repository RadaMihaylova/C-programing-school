#include "processes.h"
#include <stdio.h>
#include <string.h>

void printmenu(){
    printf("Menu\n");
    printf("1. Create new process\n");
    printf("2. List All Processes\n");
    printf("3. Stop process\n");
    printf("4. Exit\n");
}

int main(){
    while(1){
        printmenu();
        printf("Option: ");
        int option;
        scanf("%d", &option);
        while(getchar()!='\n');
        switch(option){
        case 1:{
            printf("Process name: ");
            char name[MAX_NAME_LEN];
            fgets(name, MAX_NAME_LEN, stdin);
            char *p = strchr(name, '\n');
            if (p) *p = 0;
            int id = createnewprocess(name);
            if (id == 0){
                printf("Maximum number of processes reached.\n");
            }
            else {
                printf("Process created with Id: %d\n", id);
            }
            break;
        }
        case 2:
            listproccesses();
            break;
        case 3:{
            printf("Process Id to stop: ");
            int id;
            scanf("%d", &id);
            stopprocess(id);
            break;
        }
        case 4:
            return 0;
        default:
            printf("Invalid menu option\n");
            break;
        }
    }
}
