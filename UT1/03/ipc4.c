#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pipe1[2], pipe2[2];
    int numAleatorio, factorial = 1;

    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) { // Hijo
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], &numAleatorio, sizeof(numAleatorio));

        for (int i = 1; i <= numAleatorio; i++) {
            factorial = factorial * i;
        }

        write(pipe2[1], &factorial, sizeof(factorial));

    } else { // Padre
        close(pipe1[0]);
        close(pipe2[1]);

        srand(time(NULL));
        numAleatorio = (rand() % 10) + 1;

        write(pipe1[1], &numAleatorio, sizeof(numAleatorio));

        read(pipe2[0], &factorial, sizeof(factorial));

        printf("\nEl factorial de %d es %d", numAleatorio, factorial);
    }

    return 0;
}