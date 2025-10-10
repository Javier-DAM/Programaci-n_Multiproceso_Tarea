#include <stdio.h> //Poder trabajar en C
#include <unistd.h> //Habilita utilizar Fork();
#include <sys/types.h> //Habilita utilizar getpid(); y getppid();
#include <sys/wait.h> //Habilitar el wait

void main(){
    //El proceso padre deberá crear un proceso hijo que mostrará el nombre del alumno
    pid_t pid;
    pid = fork();

    if (pid == 0){
        printf("\nHola, soy Javier y este es el proceso: %d y mi proceso padre es %d", getpid(), getppid());
        int pid = getpid();
    }

    if (pid > 0 ){
        wait(NULL);
        printf("\nSoy el proceso padre y mi pid es: %d y mi hijo es %d", getpid(), pid);    
    }

    if (pid < 0){
        printf("Error");
    }
}
