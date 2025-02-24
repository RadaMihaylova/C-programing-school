#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_PROCESSES 5
#define MAX_NAME_LEN 31

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Process;

extern Process processes[MAX_PROCESSES];
extern int processescount;

int createnewprocess(const char *name);
void stopprocess(int id);
void listproccesses();

#endif // PROCESSES_H
