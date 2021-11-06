#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define hijo    0
#define error   -1
int main(){
    //fd[0] es la opcion de lectura del pipe
    //fd[1] es la opcion de escritura de pipe
    int fd[2];// va guardar si es opcion de escritura o lectura
    pid_t pidP;
    char buf[20];
    int n_bytes;

    pipe(fd);// se debe validar el error
    pidP = fork();

    switch(pidP){
        case hijo:
            close (fd[0]);
            write(fd[1],"hola =)",7);
            close(fd[1]);
            exit(0);
            break;

        case error:
            break;
        default:
            close (fd[1]);
            n_bytes = read(fd[0],buf,sizeof(buf));
            printf("Padre lee %d : %s",n_bytes,buf);
            close(fd[0]);
            break;
    }

}