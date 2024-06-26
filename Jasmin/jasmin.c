#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.tab.h"
#include "tipoNo.h"

int id_cont, label_cont;

int getNumItems(Item *i){
	int cont = 0;
	while(i != NULL){
		cont++;
		i = i->prox;
	}
	return cont;
}

void printLabel(){
	fprintf("L%d", label_cont);
	label_cont++;
}

void printParametros(Item *prms){
	printf("%s ", getIdTipo(prms->arv->id.tipo));
	printf("%s", prms->arv->id.name);

	if (prms->prox != NULL){
		printf(", ");
		printParametros(prms->prox);
	}
}

void printVariaveis(Item *vars){
	printf("%s", vars->arv->id.name);

	if (vars->prox != NULL){
		printf(", ");
		printVariaveis(vars->prox);
	}
}

void printDeclaracao(Declaracao *decl){
	printf("%s ", getIdTipo(decl->tipo));
	printVariaveis(decl->vars);
	printf(";\n");
}

void printDeclaracoes(ListaDecl *decl){
	printDeclaracao(decl->decl);
	if (decl->prox != NULL)
		printDeclaracoes(decl->prox);
}

void printNo(tipoNo *cmd){
	
	switch(cmd->type){
		case typeInt:
			fprintf("ldc %d\n", cmd->inteiro.val);
			printf("%d", cmd->inteiro.val);
			break;
		case typeFloat:
			fprintf("ldc %f\n", cmd->real.val);
			printf("%f", cmd->real.val);
			break;
		case typeString:
			fprintf("ldc %s\n", cmd->string.str);
			printf("%s", cmd->string.str);
			break;
		case typeId:
			switch (cmd->id.tipo){
				case typeInt:
					fprintf("iload %d\n", cmd->id.i);
					break;
				case typeFloat: 
					fprintf("fload %d\n", cmd->id.i);
					break;
				case typeString:
					fprintf("aload %d\n", cmd->id.i);
					break;
			}
			printf("%s", cmd->id.name);
			break;
		case typeOpr:
			switch(cmd->opr.opr){
				case 1: // Chama Função
					fprintf("invokestatic output/%s", cmd->opr.op[0]->id.name);
					// printNo(cmd->opr.op[0]);
					// printf("(");
					// if (cmd->opr.op[1]){	
					// 	printNo(cmd->opr.op[1]);
					// }
					// printf(")");
					break;
				case 2: // Parâmetros da Função
					printNo(cmd->opr.op[0]);
					if (cmd->opr.op[1]){
						printf(", ");
						printNo(cmd->opr.op[1]);
					}
					break;
				case SIM_ADICAO:
					printNo(cmd->opr.op[0]);
					printf("+");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MULTIPLICACAO:
					printNo(cmd->opr.op[0]);
					printf("*");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_SUBTRACAO:
					printNo(cmd->opr.op[0]);
					printf("-");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_DIVISAO:
					printNo(cmd->opr.op[0]);
					printf("/");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_IGUAL:
					printNo(cmd->opr.op[0]);
					printf("=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_IGUALIGUAL:
					printNo(cmd->opr.op[0]);
					printf("==");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_DIFERENTE:
					printNo(cmd->opr.op[0]);
					printf("!=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MAIORQUE:
					printNo(cmd->opr.op[0]);
					printf(">");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MENORQUE:
					printNo(cmd->opr.op[0]);
					printf("<");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MAIOROUIGUAL:
					printNo(cmd->opr.op[0]);
					printf(">=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_MENOROUIGUAL:
					printNo(cmd->opr.op[0]);
					printf("<=");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_E:
					printNo(cmd->opr.op[0]);
					printf("&&");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_OU:
					printNo(cmd->opr.op[0]);
					printf("||");
					printNo(cmd->opr.op[1]);
					break;
				case SIM_NEGACAO:
					printf("!");
					printNo(cmd->opr.op[0]);
					break;
				case COM_RETORNO:
					if (cmd->opr.op[0] != NULL){
						if (cmd->opr.op[0]->type == typeInt || cmd->opr.op[0]->id.tipo == typeInt)
							fprintf("ireturn\n");
						else if (cmd->opr.op[0]->type == typeFloat || cmd->opr.op[0]->id.tipo == typeFloat)
							fprintf("freturn\n");
						else if (cmd->opr.op[0]->type == typeString || cmd->opr.op[0]->id.tipo == typeString)
							fprintf("areturn\n");
					} else {
						fprintf("return\n");
					}
					// printf("return ");
					// if (cmd->opr.op[0] != NULL)
					// 	printNo(cmd->opr.op[0]);
					break;
				case COM_SE:
					printf("if(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					break;
				case COM_SENAO:
					printf("if(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					printf("else{\n");
					printComandos(cmd->opr.rep->senao);
					printf("}");
					break;
				case COM_ENQUANTO:
					printf("while(");
					printNo(cmd->opr.op[0]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
					break;
				case COM_IMPRIME:
					printf("print(");
					printNo(cmd->opr.op[0]);
					printf(")");
					break;
				case COM_LER:
					printf("read(");
					printNo(cmd->opr.op[0]);
					printf(")");
					break;
				case COM_PARA:
					printf("for(");
					printNo(cmd->opr.op[0]);
					printf(";");
					printNo(cmd->opr.op[1]);
					printf(";");
					printNo(cmd->opr.op[2]);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}");
				case COM_FACA:
					printf("do{\n");
					printComandos(cmd->opr.rep->cmds);
					printf("}while(");
					printNo(cmd->opr.op[0]);
					printf(")");
			}
			break;
	}
}

void printComandos(Item *cmds){
	printNo(cmds->arv);
	printf(";\n");
	if (cmds->prox != NULL)
		printComandos(cmds->prox);
}

void printBloco(Bloco *blc){
	printf("{\n");
	if (blc->decl)
		printDeclaracoes(blc->decl);
	if (blc->cmds)
		printComandos(blc->cmds);
	printf("}\n");
}

void printFuncao(Funcao *f){
    if (!strcmpr(f->no->id.name, "main")){
        fprintf("
        .method public static main([Ljava/lang/String;)V
        .limit locals %d\n
		.limit stack 100
        ; code start
        ", getNumItems(f->tbl->syms));
    } else {
        // hashmap_set(fun_map, f->no->id.name, (void*) f);
        // id_map = hashmap_create(HASHMAP_BUCKET_SZ);
        // id_cont = getNumItems(f->prms);
        // fprintf(".method public static %s", f->no->id.name);
        // for (int i = 0; i < vector_size(f->prms); i++) {
        //     symbol* smb = vector_get(fun->params, i);
        //     hashmap_set(id_map, smb->id, (void*) smb);
        // }
        // write_code("\t.limit locals %d", getNumItems(f->tbl->syms));
        // write_code("\t.limit stack 100");
    }
	printf("%s ", getIdTipo(f->no->id.tipo));
	printf("%s", f->no->id.name);
	
	printf("(");
	if (f->prms != NULL)
		printParametros(f->prms);
	printf(")");

	if (f->blc != NULL)
		printBloco(f->blc);
	
    if (!strcmp(f->no->id.name, "main")){
        fprintf("
        ; code end
        return
        .end method
        ");
    } else {
        // hashmap_delete(id_map);
        // write_const(type);
        // write_return(type);
        // write_code(".end method\n");
    }
	printf("\n");
	if (f->prox != NULL)
		printFuncao(f->prox);
}

void printPrograma(Funcao *fun){
	label_cont = 0;
	id_cont = 0;
    FILE *f = fopen("output.j", "w");
    // write_code(concat(".source ", source_file");
	fprintf("
    .class public output\n.super java/lang/Object\n
	.method public <init>()V
		aload_0
		invokenonvirtual java/lang/Object/<init>()V
		return
	.end method\n
    ");

    fprintf("
	.method public static output_int(I)V
		.limit locals 5
		.limit stack 5
		getstatic java/lang/System/out Ljava/io/PrintStream;
		iload 0  ; the argument to function
		invokevirtual java/io/PrintStream/print(I)V
		return
	.end method\n
	.method public static output_float(F)V
		.limit locals 5
		.limit stack 5
		getstatic java/lang/System/out Ljava/io/PrintStream;
		fload 0  ; the argument to function
		invokevirtual java/io/PrintStream/print(F)V
		return
	.end method\n
	.method public static output_str(Ljava/lang/String;)V
		.limit locals 5
		.limit stack 5
		getstatic java/lang/System/out Ljava/io/PrintStream;
		aload 0
		invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
		return
	.end method\n
	.method public static outputln()V
		.limit locals 5
		.limit stack 5
		getstatic java/lang/System/out Ljava/io/PrintStream;
		invokevirtual java/io/PrintStream/println()V
		return
	.end method\n
    ");
    printFuncao(fun);
    fclose(f);
}