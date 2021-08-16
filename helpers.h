void generateStyle(int numberDashes, char style){
	for (int index = 0; index < numberDashes; ++index)
	{
		printf("%c", style);
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
	generateStyle(35, '*');
	printf("|Seja bem vindo ao show dos BITS |\n");
	generateStyle(35, '*');
	printf("\033[0m");
}

void farewell() {
	printf("\033[1;32m");
	generateStyle(35, '-');
	printf("|Obrigado por jogar SHOW DOS BITS |\n");
	generateStyle(35, '-');
	printf("\033[0m\n\n\n");
	exit(0);
}


int generateMainMenu(int numOptions, char **texts){
	int op=0;

	generateStyle(35, '*');
	for (int index = 0; index < numOptions; ++index)
	{
		printf("%d - %s\n", index + 1, texts[index]);	
	}
	printf("\033[1;32mSua opcao eh? \033[0m");
	setbuf(stdin, NULL);
	scanf("%d", &op);
	generateStyle(35, '*');
	return op;
}

void generalText(char *text){
	printf("\033[1;32m");
	generateStyle(35, '*');
	printf("|%s |\n", text);
	generateStyle(35, '*');
	printf("\033[0m");
}
