#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;
    pid_t abuelo = getpid(); // Guardamos el PID del proceso original (abuelo)

    pid1 = fork();

    if (pid1 == 0) {
        // Hijo 1
        printf("\nSoy el proceso %d, mi padre es %d y mi abuelo es %d", 
               getpid(), getppid(), abuelo);
    } else {
        // Padre (proceso principal)
        pid2 = fork();

        if (pid2 == 0) {
            // Hijo 2
            pid_t padre_hijo2 = getpid(); // Guardamos el PID del padre (para los nietos)
            pid3 = fork();

            if (pid3 == 0) {
                // Nieto del proceso principal
                printf("\nSoy el proceso %d, mi padre es %d y mi abuelo es %d", 
                       getpid(), getppid(), abuelo);
            } else {
                wait(NULL); // Espera a su hijo (nieto)
                printf("\nSoy el proceso %d, mi padre es %d y mi abuelo es %d", 
                       getpid(), getppid(), abuelo);
            }

        } else {
            // Padre (proceso principal) crea otro hijo
            pid4 = fork();

            if (pid4 == 0) {
                // Hijo 3
                printf("\nSoy el proceso %d, mi padre es %d y mi abuelo es %d", 
                       getpid(), getppid(), abuelo);
            } else {
                // El proceso padre original espera a todos sus hijos
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("\nSoy el proceso padre original %d (no tengo abuelo)", getpid());
            }
        }
    }

    return 0;
}