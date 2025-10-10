#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    pid_t pid1, pid2, pid3, pid4, pid5;
        
    if(pid1 > 0){//proceso padre

        pid2 = fork(); 
        if (pid2 == 0){ //Proceso hijo 2
            pid4 = fork();
            if (pid4 == 0){ //Proceso hijo 4
                printf("\nSoy el proceso %d y mi padre es %d",getpid(), getppid()); 
                exit(0);
            }
            wait(NULL);
            printf("\nSoy el proceso %d y mi padre es %d",getpid(), getppid());
            exit(0);
        }

        pid3 = fork();
        if (pid3 == 0){ //Proceso hijo 3
            pid5 = fork();
            if(pid5 == 0){ //Proceso hijo 5
                printf("\nSoy el proceso %d y mi padre es %d",getpid(), getppid());
                exit(0);
            }
            wait(NULL);
            printf("\nSoy el proceso %d y mi padre es %d",getpid(), getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        printf("\nSoy el proceso padre principal, mi pid es: %d",getpid());
    }
    
    return 0;
}