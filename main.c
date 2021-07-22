#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int menu();

int main(int argc, char const *argv[])
{
	hello_greeting();
	menu();
	return 0;
}


int menu(){
	int op;
	char *words[] = {"Gravar perguntas", "Jogar", "Ver records", "Sair"};
	printf("O que você deseja fazer?\n");
	op = generateMenus(4, words);
	printf("Sua opcao foi %d\n", op);
	switch(op){
		case 1: 
			break;
		case 2: 
			break;
		case 3: 
			break;
		case 4: 
			break;
		default: 
			printf("\033[1;31mOPCAO INVALIDA\n\033[0m");
	return 0;
}

	
}