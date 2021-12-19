#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  
	if(argc<2){
		printf("Debes instroducir comandos \n");
		exit(1);
	}
	if(argc > 2){ 
		char *const cmd[] = {argv[1], argv[2], NULL};
		int i;

		while (1) {
			pid_t pid;
			if (strcmp("exit",argv[1]) == 0) {
				printf("[Exit - :)]\n");
				break;
			}
			pid = fork();
			if (pid < 0) {
				perror("No se pudo crear un proceso\n");
				exit(1);				
				//break;
			} else if (pid == 0) {
				//cmd = de_cadena_a_vector(argv[1]);
				execvp(cmd[0],cmd);
				perror("Return from execlp() not expected");
				exit(EXIT_FAILURE);
			} else {
				wait(NULL);
				break;
			}
		}
	}
	else{
    
		char **vector;
		int i;

		while (1) {
			pid_t pid;
			if (strcmp("exit",argv[1]) == 0) {
				printf("[Exit - :)]\n");
				break;
			}
			pid = fork();
			if (pid < 0) {
				perror("No se pudo crear un proceso\n");
				exit(1);				
				//break;
			} else if (pid == 0) {
				vector = de_cadena_a_vector(argv[1]);
				execvp(vector[0],vector);
				perror("Return from execlp() not expected");
				exit(EXIT_FAILURE);
			} else {
				wait(NULL);
				break;
			}
		}
	}




  return 0;
}