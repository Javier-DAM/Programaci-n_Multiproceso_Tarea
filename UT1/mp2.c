#include <stdio.h> //Poder trabajar en C
#include <unistd.h> //Habilita utilizar Fork();
#include <sys/types.h> //Habilita utilizar getpid(); y getppid();
#include <sys/wait.h> //Habilitar el wait

int main(){

    pid_t pid1, pid2, pid3;
    pid1 = fork();

    if (pid1 == 0){
        pid1 = fork();

        if (pid2 == 0){
            pid3 = pid2;
            printf("\n Soy el proceso hijo y mi pid es %d y mi proceso padre es %d", getpid(), getppid());

        }else{
        printf("\n Soy el proceso padre y mi pid es %d y mi proceso padre es %d", getpid(), getppid());

        }
    }else{
        printf("\n Soy el proceso abuelo y mi pid es %d y mi proceso padre es %d", getpid(), getppid());

    }
    return 0;
}