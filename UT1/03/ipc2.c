#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2], valoresTotales, sumatoria = 0;
    char calculo[100];
    pipe(fd);

    if (fork() == 0) { // Proceso hijo
        close(fd[1]);
        read(fd[0], calculo, sizeof(calculo));
        printf("\nSoy el proceso hijo con pid: %d", getpid());
        printf("\nResultado: %s\n", calculo);

    } else { // Proceso padre
        close(fd[0]);
        printf("\n¿Cuántos valores quieres introducir?: ");
        scanf("%d", &valoresTotales);

        int datos[valoresTotales];

        for (int i = 0; i < valoresTotales; i++) {
            printf("Ingresa el dato entero %d: ", i + 1);
            scanf("%d", &datos[i]);
        }

        for (int i = 0; i < valoresTotales; i++) {
            sumatoria += datos[i];
        }

        sprintf(calculo, "La suma de los %d valores es: %d", valoresTotales, sumatoria);
        
        write(fd[1], calculo, sizeof(calculo));
    }
    return 0;
}