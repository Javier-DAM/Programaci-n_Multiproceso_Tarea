#include <stdio.h> //Poder trabajar en C
#include <unistd.h> //Habilita utilizar Fork();
#include <sys/types.h> //Habilita utilizar getpid(); y getppid();
#include <sys/wait.h> //Habilitar el wait

int main(){

    pid_t pid1;
    pid1 = fork();

    if (pid1 == 0){
        pid1 = fork();

        if (pid1 == 0){

        printf("\nsoy el proceso 3, mi pid es %d y el de mi pare es %d", getpid(), getppid());

        }else{

            wait(NULL);
            wait(NULL);
            printf("\nsoy el proceso 1 y mi pid es %d", getpid());

        }
        sleep(10);
        sleep(10);
        printf("\nsoy el proceso 2 y mi pid es %d, despierto", getpid());  
    }
    return 0;
}