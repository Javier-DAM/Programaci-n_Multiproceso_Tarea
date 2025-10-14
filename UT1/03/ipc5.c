#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipe1[2], pipe2[2];
    int dniNumero, calcularLetra;
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    char letraDNI;

    pipe(pipe1); // hijo -> padre
    pipe(pipe2); // padre -> hijo

    if (fork() == 0) { // Hijo
        close(pipe1[0]); // cierra lectura del primer pipe
        close(pipe2[1]); // cierra escritura del segundo pipe

        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dniNumero);

        // Envía el número al padre
        write(pipe1[1], &dniNumero, sizeof(dniNumero));

        // Espera la letra calculada
        read(pipe2[0], &letraDNI, sizeof(letraDNI));

        printf("La letra del NIF es: %c\n", letraDNI);

        close(pipe1[1]);
        close(pipe2[0]);

    } else { // Padre
        close(pipe1[1]); // cierra escritura del primer pipe
        close(pipe2[0]); // cierra lectura del segundo pipe

        // Lee el número del hijo
        read(pipe1[0], &dniNumero, sizeof(dniNumero));

        calcularLetra = dniNumero % 23;
        letraDNI = letras[calcularLetra];

        // Envía la letra al hijo
        write(pipe2[1], &letraDNI, sizeof(letraDNI));

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
