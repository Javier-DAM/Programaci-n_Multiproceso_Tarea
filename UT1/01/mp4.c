#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){

    printf("CCC \n");

    if (fork()!=0){

        printf("BBB \n"); //Cambiamos AAA por BBB

        } else {

            printf("AAA \n"); //Cambiamos BBB por AAA
        }

    exit(0);
}