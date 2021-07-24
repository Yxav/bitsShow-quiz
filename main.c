#define MAX_QUESTIONS_ALTERNATIVES 4
#define MAX_QUESTIONS 10


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structs.h"
#include "helpers.h"

int menu();
int recordQuestions();
void exitGame();

Question questions[10];
int questionController=0;

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
	
	if(1 > op || op > 4) {
		printf("\033[1;31mOPCAO INVALIDA\n\033[0m");
		printf("O que você deseja fazer?\n");
		menu();


	}
	printf("Sua opcao foi %d\n", op);


		switch(op){
		case 1: 
			generalText("\033[1;32mGRAVAR PERGUNTAS:               \033[0m");
			recordQuestions();
			break;
		case 2:
			break;
		case 3: 
			break;
		case 4: 
			exitGame();
			break;
		default: 
			break;


	return 0;
	}
}

int recordQuestions(){

	char op='S';
	Question question;

	printf("\033[1;35mInsira os dados da sua pergunta na seguinte ordem\n");
	printf("1 - Pergunta\n");
	printf("2 - Alternativa correta (somente letras serão aceitas)\n");
	printf("3 - As alternativas (ex: A - Qual a capital do Brasil?) \n");
	printf("SOMENTE QUATRO ALTERNATIVAS SÃO ACEITAS\033[0m\n\n");

	while(toupper(op) == 'S'){
		printf("Insira a sua pergunta\n");
		cleanBuffer();
		fgets(question.questionDescription, sizeof(question.questionDescription), stdin);

		printf("Insira a alternativa correta\n");
		question.correctAlternative = getchar();
		
		while(question.correctAlternative < 65 || question.correctAlternative > 100) {
			printf("\033[1;31mPor favor, caracteres entre 'a' e 'd'\n\033[0m");
			cleanBuffer();
			question.correctAlternative = getchar();
		}


		printf("Agora, insira as alternativas:\n");
		cleanBuffer();
		for (int index = 0; index < MAX_QUESTIONS_ALTERNATIVES; ++index)
		{
			question.alternative[index].option = index + 65;	
			printf("Alternativa:\n");
			fgets(question.alternative[index].nameAlternative, sizeof(question.alternative[index].nameAlternative), stdin);
			
		}
		printf("Pergunta feita:\n ");
		printf("Pergunta: %s\n", question.questionDescription);
		printf("Alternativa correta: %c\n", question.correctAlternative);
		printf("alternativas:\n");
		for (int index = 0; index < MAX_QUESTIONS_ALTERNATIVES; ++index)
		{
			printf("%c - %s", question.alternative[index].option, question.alternative[index].nameAlternative);
		}
		questions[questionController] = question;
		questionController++;
		generalText("PERGUNTA CRIADA COM SUCESSO!");

		printf("Deseja criar outra pergunta? [S]im \\ [N]ao\n");
		op = getchar();

	}
	printf("\033[1;33mVoltando para o menu......\n\033[0m");
	menu();
}


void exitGame() {

	char op;
	cleanBuffer();
	printf("\033[1;31mVOCE DESEJA REALMENTE SAIR?: [S]im \\ [N]ao  \033[0m");
	op= getchar();
		
	if (toupper(op) == 'S') exit(0); 

	menu();
}
