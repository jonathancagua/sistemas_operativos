/**
 * @file fork-example.c
 * @author Jonathan
 * @brief uso de fork:
 * Fork(). Proceso padre, hijo, huerfano , zombie
 * -pid_t fork(void)
 * -pid_t wait(int *wstatus);
 * -WEXITSTATUS(wstatus);
 * 
 * - comandos:
 *   kill -9 PID-proceso --> kill -9 27374
 *   ps -lf para ver los procesos
 * 
 * - pagina 
 *   https://man7.org/linux/man-pages/man2/wait.2.html
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#define CANT_HIJOS 8
int variable = 8;

int generar_aleatorio(void){
    int numero;
    srand(getpid());
    numero = (rand() % 256);
    printf("HIJO: PID = %d, numero aleatorio %d \n\r",getpid(),numero);
    return numero;
}
int main(void){
    pid_t pidH;
    int status;
    for(int i=0; i<CANT_HIJOS ; i++){
        pidH = fork();
        if(pidH > 0){
            continue;
        }
        else if(pidH == 0){

            exit(generar_aleatorio());
        }
        else{
            //error
        }
    }
    for(int i=0;i<CANT_HIJOS;i++){
        pidH = wait(&status);
        printf("Padre de PID %d, PID hijo %d,st = %d \n\r",getpid(),pidH,WEXITSTATUS(status));

    }

    while(1){
        sleep(2);
    }

    return 0;
}