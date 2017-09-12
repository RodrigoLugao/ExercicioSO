#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

 void *escreve(void *argumento){ //printa na tela
    int *x_ptr = (int *)argumento;
	while((*x_ptr)>0){
		printf("x: %d\n", *x_ptr);
	}
	
	return NULL;
 }


 int main (int argc, char *argv[]){
    pthread_t minha_thread;
	int x = 1;
	int entr = 1;
	int resultado;
	if(pthread_create(&minha_thread, NULL, escreve, &x)) {

		fprintf(stderr, "Erro ao criar a thread\n");
		return 1;

	}
	printf("Uma thread printa constantemente o ultimo numero digitado(começando por 1) \n
	       enquanto a outra aguarda o usuario digitar um numero\n
	       Pressione enter para continuar:\n");
	scanf("");
    while(entr > 0){
		resultado = scanf("%d", &entr);
		x = entr;
		if (resultado == EOF) {
				entr = 0;
		}
		if (resultado == 0) {
			while (fgetc(stdin) != '\n');
			entr = 0;
		}	
	}
	return 0;
	
 }
