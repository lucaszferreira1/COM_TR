#include <stdio.h>
#include "expr.tab.h"


extern FILE *yyin;

int main(){
	FILE *file = fopen("input.txt", "r");
	if (file == NULL){
		perror("Error opening file!");
		return 1;
	}
	yyin = stdin;
	printf("Digite uma express�o:");
	yyparse();
	return 0;
}

