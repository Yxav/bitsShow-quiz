void generateDashes(int numberDashes){
	for (int index = 0; index < numberDashes; ++index)
	{
		printf("*");
	}
	printf("\n");
}

void cleanBuffer(void) // setbuf doesn't working in some cases;
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}


void greeting() {
	printf("\033[1;32m");
	generateDashes(35);
	printf("|Seja bem vindo ao show do bilhao |\n");
	generateDashes(35);
	printf("\033[0m");
}

void farewell() {
	printf("\033[1;32m");
	generateDashes(35);
	printf("|Obrigado por jogar SHOW DO BILHAO |\n");
	generateDashes(35);
	printf("\033[0m");
}


int generateMainMenu(int numOptions, char **texts){
	int op=0;
    setbuf(stdin, NULL);
	generateDashes(35);
	for (int index = 0; index < numOptions; ++index)
	{
		printf("%d - %s\n", index + 1, texts[index]);	
	}
	printf("\033[1;32mSua opcao eh? \033[0m");
	scanf("%d", &op);
	generateDashes(35);
	return op;
}

void generalText(char *text){
	printf("\033[1;32m");
	generateDashes(35);
	printf("|%s |\n", text);
	generateDashes(35);
	printf("\033[0m");
}















