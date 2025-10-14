#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){

int fd[2];
double dato1, dato2, sumatoria, resta, division, multiplicacion;
char mensaje[100];
char calculo[100];
pipe(fd);

    if (fork() == 0){ //Proceso hijo

        close(fd[1]);
        read(fd[0],calculo,sizeof(calculo));
        printf("\n Resultado: %s", calculo);


    }else{ //Proceso padre

        close(fd[0]);
        srand(time(NULL));
        dato1 = (rand() % 50) + 1;
        dato2 = (rand() % 50) + 1;

        sumatoria = dato1 + dato2;
        resta = dato1 - dato2;
        division = dato1/dato2;
        multiplicacion = dato1 * dato2;

        sprintf(calculo, 
            "\n%.0f + %.0f = %.0f"
            "\n%.0f - %.0f = %.0f"
            "\n%.0f / %.0f = %.0f"
            "\n%.0f * %.0f = %.0f"
            , dato1, dato2, sumatoria, dato1, dato2, resta, dato1, dato2, division, dato1, dato2, multiplicacion);
        
        write(fd[1], calculo, sizeof(calculo));
    }
}