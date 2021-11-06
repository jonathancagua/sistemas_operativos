/**
 * @file fork-example.c
 * @author Jonathan
 * @brief uso de Signal
 * @version 0.1
 * @date 2021-11-06
 * -comando kill -SIGALRM PID ejemplo: kill -SIGALRM 36444
 *  con ese comando le llega la alarma al handler
 * @copyright Copyright (c) 2021
 * 
 */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void SignalHandler(int sig){
    printf("Signal recibida valor %d \n", sig);
}
int main(void){
    signal(SIGALRM, &SignalHandler);
    while(1){
        sleep(2);
        printf("Esperando senales \n\r");
    }
    return 0;
}