void generateDashes(int numberDashes){
	for (int index = 0; index < numberDashes; ++index)
	{
		printf("*");
	}
	printf("\n");
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


int generateMenus(int numOptions, char **texts){
	int op=0;
	generateDashes(35);
	for (int index = 0; index < numOptions; ++index)
	{
		printf("%d - %s\n", index, texts[index]);	
	}
	printf("\033[1;32mSua opcao eh? \033[0m");
	scanf("%d", &op);
	generateDashes(35);
	return op;
}















