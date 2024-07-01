all: main

expr.tab.c expr.tab.h: expr.y
	bison -d expr.y 

lex.yy.c: expr.l
	flex expr.l

run: 
	./expr
	java -jar Jasmin/jasmin.jar Jasmin/output.j
	java output

main: lex.yy.c expr.tab.c 
	./consertotabh.sh
	gcc Jasmin/jasmin.c lex.yy.c expr.tab.c exprMain.c -o expr -g

clean: 
	rm -f lex.yy.c expr.tab.c expr.tab.h

