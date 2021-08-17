#define MAX_QUESTIONS_ALTERNATIVES 4
#define MAX_QUESTIONS 10
#define INITIAL_OPTION 65
#define END_OPTION 68


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structs.h"
#include "helpers.h"

int menu();
int recordQuestions();
void exitGame();
int playQuiz();


Question questions[MAX_QUESTIONS];
int questionController=0, points=0;


int main(int argc, char const *argv[])
{
	greeting();
	menu();
	farewell();
	return 0;
}


int menu(){
	int op;
	char *words[] = {"Gravar perguntas", "Jogar", "Sair"};
	printf("O que você deseja fazer?\n");
	op = generateMainMenu(3, words);

	if(1 > op || op > 3) {
		printf("\033[1;31mOPCAO INVALIDA\n\033[0m");
		printf("O que você deseja fazer?\n");
		menu();
	}

		switch(op){
		case 1: 
			generalText("\033[1;32mGRAVAR PERGUNTAS:               \033[0m");
			recordQuestions();
			break;
		case 2:
			if(questionController==0){
				printf("\033[1;31mVOCE NAO TEM PERGUNTAS GRAVADAS\033[0m\n\n");
				recordQuestions();
				break;
			}

			points = playQuiz();
			printf("\033[1;35mVoce fez %d pontos\n\n\033[0m", points);
			
			printf("\033[1;35mO que resulta em B$%.2f reais de bits imaginarios\n\n\033[0m", points * (0.15));


			break;
		case 3: 
			exitGame();
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
	printf("2 - As alternativas (ex: A - Qual a capital do Brasil?) \n");
	printf("3 - Alternativa correta (somente letras serão aceitas)\n");
	printf("SOMENTE QUATRO ALTERNATIVAS SÃO ACEITAS\033[0m\n\n");

	while(toupper(op) == 'S'){
		printf("Insira a sua pergunta\n");
		cleanBuffer();
		fgets(question.questionDescription, sizeof(question.questionDescription), stdin);



		printf("Agora, insira as alternativas:\n");
		for (int index = 0; index < MAX_QUESTIONS_ALTERNATIVES; ++index)
		{
			question.alternative[index].option = index + 65;	
			printf("%c - Alternativa:\n", question.alternative[index].option);
			fgets(question.alternative[index].nameAlternative, sizeof(question.alternative[index].nameAlternative), stdin);
			
		}

		printf("Insira a alternativa correta\n");
		question.correctAlternative = toupper(getchar());
		
		while(question.correctAlternative < INITIAL_OPTION || question.correctAlternative > END_OPTION) {
			printf("\033[1;31mPor favor, caracteres entre 'a' e 'd'\n\033[0m");
			cleanBuffer();
			question.correctAlternative = toupper(getchar());
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
		cleanBuffer();
		op = getchar();

	}

	printf("\033[1;33mVoltando para o menu......\n\033[0m");
	menu();
}

int playQuiz(){
	char currentAlternative;

	for (int indexQuestion = 0; indexQuestion < questionController; ++indexQuestion)
	{
		printf("Pergunta numero: %d \n", indexQuestion+1);
		printf("\033[1;33m%s\n\033[0m", questions[indexQuestion].questionDescription);
		printf("Alternativas:\n");
		for (int index = 0; index < MAX_QUESTIONS_ALTERNATIVES; ++index)
		{
			printf("\033[1;36m %c - %s\033[0m", questions[indexQuestion].alternative[index].option, questions[indexQuestion].alternative[index].nameAlternative);
		}

		printf("Qual a alternativa correta?\n\n");
		cleanBuffer();
		currentAlternative = toupper(getchar());

		if (currentAlternative == questions[indexQuestion].correctAlternative){
			points++;
			printf("\033[1;32mPARABENS, VOCE ACERTOU!\n\033[0m");
		} else {
			printf("\033[1;31mQUE PENA! VOCE ERROU!\n\033[0m");
			printf("A alternativa correta é: %c!\n", questions[indexQuestion].correctAlternative);
		}
	}

	return points;

}

void exitGame() {

	char op;
	cleanBuffer();
	printf("\033[1;31mVOCE DESEJA REALMENTE SAIR?: [S]im \\ [N]ao  \033[0m");
	op= getchar();
		
	if (toupper(op) == 'S') farewell(); 

	menu();
}
