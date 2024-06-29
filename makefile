all: main

expr.tab.c expr.tab.h: expr.y
	bison -d expr.y 

lex.yy.c: expr.l
	flex expr.l

main: lex.yy.c expr.tab.c 
	./consertotabh.sh
	gcc Jasmin/jasmin.c lex.yy.c expr.tab.c exprMain.c -o expr -g
	./expr
	java -jar Jasmin/jasmin.jar output.j

clean: 
	rm -f lex.yy.c expr.tab.c expr.tab.h