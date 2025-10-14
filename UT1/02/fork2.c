#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0) {
        // Proceso hijo 1
        printf("\nSoy el proceso %d y mi padre es %d, y la suma de ambos es (%d)", 
               getpid(), getppid(), getpid() + getppid());
    } else {
        // Proceso padre crea un segundo hijo
        pid2 = fork();

        if (pid2 == 0) {
            // Proceso hijo 2
            printf("\nSoy el proceso %d y mi padre es %d, y la suma de ambos es (%d)", 
                   getpid(), getppid(), getpid() + getppid());
        } else {
            // Proceso padre crea un tercer hijo
            pid3 = fork();

            if (pid3 == 0) {
                // Proceso hijo 3
                printf("\nSoy el proceso %d y mi padre es %d, y la suma de ambos es (%d)", 
                       getpid(), getppid(), getpid() + getppid());
            } else {
                // Proceso padre espera a los tres hijos
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("\nSoy el proceso padre %d y mi padre es %d, y la suma de ambos es (%d)", 
                       getpid(), getppid(), getpid() + getppid());
            }
        }
    }

    return 0;
}