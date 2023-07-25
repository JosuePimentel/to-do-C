#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define C 30
#define T 50
// step 01 -> Ver os ToDos
// step 02 -> Completar um Todo
// step 03 -> Filtro
// step 04 -> Add 
// step 05 -> Sair do app 

#define max_task 100

typedef struct {
    char desc[100];
    int complete;
} task;

task tasks[max_task];
int totalTasks = 0, filter = 0;

int addToDo( ) {
    char description[100];

    printf("\nWrite the description of the Task: ");
    getchar();
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0'; // Remover o caractere '\n' da string
    
    task newTask;
    strcpy(newTask.desc, description);
    newTask.complete = 0;

    tasks[totalTasks] = newTask;
    totalTasks++;

    printf("Task insert Done!");
}

void escreverComplet( int index ) { 
    index < 9 ? printf("[0%i] %s - [X]\n", index+1, tasks[index].desc) : printf("[%i] %s - completed\n", index+1, tasks[index].desc);
}

void escreverNoComplet( int index ) {
    index < 9 ? printf("[0%i] %s - [ ]\n", index+1, tasks[index].desc) : printf("[%i] %s - No complet\n", index+1, tasks[index].desc);
}


// 0 -> todos
// 1 -> complets
// 2 -> no complets
void escreverToDos( ) {
    int x;
    if(filter) {
        printf("Filter define: ");
        if(filter == 1) printf("Complets\n");
        else if(filter == 2) printf("No Complets\n\n");
    }
    for( x = 0 ; x < totalTasks ; x++ ) {

        if(filter == 0) {
            if(tasks[x].complete) escreverComplet(x);
            else escreverNoComplet(x);
        } else if(filter == 1 && tasks[x].complete) {
            escreverComplet(x);
        } else if(filter == 2 && tasks[x].complete == 0) {
            escreverNoComplet(x);
        }
    }
}

void filterr() {
    printf("\nDefine the filter:\n [00] All\n [01] Complets\n [02] No complets\n");
    scanf("%i", &filter);
    filter == 1 ? printf("filter defined as completed tasks.") : (filter == 2 ? printf("filter defined as no complet tasks.") : printf("filter defined as all tasks."));
}

void completTask() {
    int indexTaskComplet;
    printf("\nWhat is index of the task that you wanna complet? ");
    scanf("%d", &indexTaskComplet);
    tasks[indexTaskComplet-1].complete = 1;
    printf("Task %i has complet.\n", indexTaskComplet);
}

void removeTask() {
    int indexTaskRemove, x;
    printf("\nWhat is index of the task that you wanna remove? ");
    scanf("%i", &indexTaskRemove);
    for( x = indexTaskRemove-1 ; x < totalTasks ; x++ ) {
        tasks[x] = tasks[x+1];
    } 
    totalTasks--;
    printf("Task %i has removed.\n", indexTaskRemove);
}

void nextStepe( int nextStep ) {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else 
        system("clear");
    #endif

    if(nextStep == 1) 
        escreverToDos( );
    else if (nextStep == 2) 
        completTask();
    else if (nextStep == 3)
        filterr();
    else if (nextStep == 4) 
        addToDo();
    else if (nextStep == 5) 
        removeTask();
}

int main() {
    int nextStep, sair = 0;

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else 
        system("clear");
    #endif

    while(!sair) {
        printf("\n\nWrite the next step:\n[01] To see the Tasks. \n[02] Complete one Task. \n[03] Filter. \n[04] Add one Task. \n[05] Remove one task. \n[06] Sair.\n");
        scanf("%i", &nextStep);
        if(nextStep == 6) sair++;
        else nextStepe( nextStep );
    }

    printf("\nSee u later! GoodBye\n");

    return 0;
}