#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("\nEjercicio 1\n");

    pid_t pid1, pid2;

    pid1 = fork(); // Primer fork

    if (pid1 == 0) {
        // Proceso hijo 1
        pid2 = fork(); // Segundo fork solo en el hijo
        if (pid2 == 0) {
            // Hijo del hijo
            printf("Soy el proceso %d nieto, mi padre es %d\n", getpid(), getppid());
        } else {
            wait(NULL);
            printf("Soy el proceso %d hijo, mi padre es %d\n", getpid(), getppid());
        }
    } else {
        // Proceso padre
        wait(NULL);
        printf("Soy el proceso abuelo %d\n", getpid());
    }

    return 0;
}
