/***************************************************************************//**
  @file         myshell.c
  @authors      Elivelton Rangel, Nilvan Santana, Matheus Nishimoto, Robson Sousa
  @brief        UNIVERSIDADE FEDERAL DA BAHIA - UFBA
                Projeto prático 04: Coordenação de Tarefas
                Sistemas Operacionais (MAT566)
*******************************************************************************/

#include "utility.c"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void *cliente(void *id){

	int tid;
	tid = (int)id;

	int cabelo_cortado = 0;
	int pagou_corte = 0;

	printf("entrou na fila de fora.\n");
	sem_wait(&fila_fora);
	sem_wait(&em_pe);

	printf("entrou na fila em pe\n");
	sem_post(&fila_fora);
	sem_wait(&sofa);

	printf("sentou sofa\n");
	sem_post(&em_pe);
	sem_wait(&cadeira);

	printf("sentou na cadeira\n");
	sem_post(&sofa);

	while(cabelo_cortado == 0){
		printf("cliente %i cortando cabelo", tid);
	}

	printf("entrou na fila do caixa\n");
	sem_wait(&caixa);
	sem_post(&cadeira);

	while(pagou_corte = 0);{
		printf("cliente %i esperando para pagar", tid);
	}

	printf("cliente %i pagou e deixou a barbearia\n", tid);

	

}

int main(int argc, char *argv[]){

  sem_init(&caixa, 0, 1);
  sem_init(&cadeira, 0, 3);
  sem_init(&sofa, 0, 4);
  sem_init(&em_pe, 0, 16);
  sem_init(&fila_fora, 0, 30);

}
