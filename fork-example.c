/**
 * @file fork-example.c
 * @author Jonathan
 * @brief uso de fork:
 * Fork(). Proceso padre, hijo, huerfano , zombie
 * -pid_t for(void)
 *  Crea un nuevo proceso "hijo"
 *  el proceso hijo es un duplicado del proceso "padre"
 *  Los dos procesos tienen PIDs diferentes y corren en 
 *  direcciones de memoraia diferentes.
 *  retorna: 
 *      - en el proceso padre retorna el PID del hijo
 *      - retorna 0 en el proceso hijo
 *      - Si existe un error retorna -1, eso significa 
 *          que el hijo no fue creado
 * - comandos:
 *   kill -9 PID-proceso --> kill -9 27374
 *   ps -lf para ver los procesos
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <unistd.h>
#include <stdio.h>
int variable = 8;
int main(void){
    pid_t pidP;
    printf("--> proceso inicia con PID = %d \n\r", getpid());
    pidP = fork();
    printf("--> proceso ejecutando PID = %d pidP= %d \n\r", getpid(),pidP);

    if(pidP > 0){
        variable = 9;
        printf("proceso padre \n\r");
    }
    else if(pidP == 0){
        variable = 11;
        printf("proceso hijo \n\r");
    }
    else{
        printf("ERROR el hijo no fue creado\n\r");
    }
    while(1){
        sleep(2);
        printf("proceso ejecutando PID = %d variable = %d \n\r", getpid(),variable);
    }

    return 0;
}