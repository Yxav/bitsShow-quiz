#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"


#define MAX_QUESTIONS_ALTERNATIVES 4

int menu();
int recordQuestions();


struct alternative {
	char option;
	char nameAlternative[100];
};

struct question {
	char questionDescription[100];
	char correctAlternative;
	struct alternative alternative[MAX_QUESTIONS_ALTERNATIVES];
};


int main(int argc, char const *argv[])
{
	greeting();
	menu();
	farewell();
	return 0;
}


int menu(){
	int op;
	char *words[] = {"Gravar perguntas", "Jogar", "Ver records", "Sair"};
	printf("O que você deseja fazer?\n");
	op = generateMainMenu(4, words);
	printf("Sua opcao foi %d\n", op);
	switch(op){
		case 1: 
			generalText("GRAVAR PERGUNTAS:");
			recordQuestions();
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

int recordQuestions(){
	struct question question;

	printf("Insira os dados da sua pergunta na seguinte ordem\n");
	printf("1 - Pergunta\n");
	printf("2 - Alternativa correta (somente letras serão aceitas)\n");
	printf("3 - As alternativas (ex: A - Qual a capital do Brasil?) \n");
	printf("SOMENTE QUATRO ALTERNATIVAS SÃO ACEITAS\n\n");

    setbuf(stdin, NULL);
	printf("Insira a sua pergunta\n");
	fgets(question.questionDescription, sizeof(question.questionDescription), stdin);

    setbuf(stdin, NULL);
	printf("Insira a alternativa correta\n");
	question.correctAlternative = getchar();


	printf("Agora, insira as alternativas:\n");
	cleanBuffer();
	for (int index = 0; index < MAX_QUESTIONS_ALTERNATIVES; ++index)
	{
		printf("Caractere da Alternativa:\n");
		question.alternative[index].option = getchar();		
		printf("Alternativa:\n");
		cleanBuffer();
		fgets(question.alternative[index].nameAlternative, sizeof(question.alternative[index].nameAlternative), stdin);
		
	}
}
	