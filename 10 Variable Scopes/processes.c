#include "processes.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>

Process processes[MAX_PROCESSES];
int processescount = 0;

static int nextid = 0;

static int nextprocessid(){
    if (nextid == INT_MAX) return 0;
    nextid++;
    return nextid;
}

int createnewprocess(const char *name){
    if (processescount >= MAX_PROCESSES) return 0;
    int id = nextprocessid();
    if (id == 0) return 0;
    processes[processescount].id = id;
    strncpy(processes[processescount].name, name, MAX_NAME_LEN);
    processes[processescount].name[MAX_NAME_LEN] = 0;
    processescount++;
    return id;
}

void stopprocess(int id){
    int index = -1;
    for(int i = 0; i < processescount; i++){
        if (processes[i].id == id){
            index = i;
            break;
        }
    }
    if (index == -1) return;
    for(int i = index; i < processescount; i++){
        processes[i] = processes[i + 1];
    }
    processescount--;
}

void listproccesses(){
    for(int i = 0; i < processescount; i++){
        printf("Process Id: %d, Process Name: %s\n", processes[i].id, processes[i].name);
    }
}
