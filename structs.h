struct alternative {
	char option;
	char nameAlternative[100];
};

struct question {
	char questionDescription[100];
	char correctAlternative;
	struct alternative alternative[MAX_QUESTIONS_ALTERNATIVES];
};
typedef struct question Question;