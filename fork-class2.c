/**
 * @file fork-class2.c
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
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	pid_t pid;
	int rv;
	int sarasa;
	switch(pid = fork())
	{
		case -1:
                  perror("fork"); /* something went wrong */
                  exit(1);
		break;

		/* parent exits */
		case 0:
                  printf(" CHILD: This is the child process!\n");
                  printf(" CHILD: My PID is %d\n", getpid());
                  printf(" CHILD: My parent's PID is %d\n", getppid());
                  printf(" CHILD: Llamo a exec...\n ");
                  char* const args[] = {"/bin/ls","-lah",NULL};
                  execv("/bin/ls",args);
                  printf(" CHILD: I'm outta here!\n");
                  exit(rv);
		break;


		default:
                  printf("PARENT: This is the parent process!\n");
                  printf("PARENT: My PID is %d\n", getpid());
                  printf("PARENT: My childs PID is %d\n", pid);
                  wait(&sarasa);
                  printf("PARENT: My child's exit status is: %d\n", WEXITSTATUS(sarasa));
                  printf("PARENT: I'm outta here!\n");
            break;
	}
}

