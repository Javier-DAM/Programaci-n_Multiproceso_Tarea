#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    int fd[2];
    char mensaje[100];
    pipe(fd);

    if (fork() == 0) { // Hijo

        close(fd[1]);
        read(fd[0], mensaje, sizeof(mensaje)); //Leemos lo enviado del proceso padre
        printf("Soy el proceso hijo con pid %d\n", getpid());
        printf("Fecha/hora: %s", mensaje);

    } else { // Padre

        close(fd[0]);
        time_t t = time(NULL); //Obtenemo
        char *fecha = ctime(&t);
        write(fd[1], fecha, sizeof(mensaje));

    }
    return 0;
}