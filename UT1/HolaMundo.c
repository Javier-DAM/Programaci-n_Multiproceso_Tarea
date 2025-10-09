#include <stdio.h> //Poder trabajar en C
#include <unistd.h> //Habilita utilizar Fork();
#include <sys/types.h> //Habilita utilizar getpid(); y getppid();

int main() {

    pid_t pid; //Otorgamos un id a cada uno de los procesos
    pid = fork();

    //if pid > 0 -> Proceso padre
    //if pid = 0 -> Proceso hijo

    if (pid > 0){
        printf("\nSoy el proceso hijo, así que no crearé nada más");
    }

    if (pid==0){
        printf("\nSoy el proceso padre, así que crearé otro proceso");
        fork();
    }

    printf("\nSoy el proceso pid: %d y soy hijo de %d", getpid, getppid); //Utilizamos %d para asignar el tipo de variable, y luego el getpid o getppid para decir la variable que es.
    
    return 0;
}