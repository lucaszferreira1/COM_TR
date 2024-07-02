#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jasmin.h"
#include "../tipoNo.h"
#include "../expr.tab.h"

int label_cont;
Funcao* tbl_funcoes;
int isMain;
eTipo tipoFuncaoAtual;

Funcao* searchFuncoes(char *name){
	Funcao* f = tbl_funcoes;
	while(f != NULL){
		if (!strcmp(f->no->id.name, name))
			return f;
		f = f->prox;
	}
	printf("Erro ao procurar função na tabela de funções\n");
	exit(1);
}

int hasFloatInOpr(tipoNo *opr){
	int r1, r2;
	if (opr->type == typeOpr){
		if (opr->opr.nOps > 0)
			r1 = hasFloatInOpr(opr->opr.op[0]);
		if (opr->opr.nOps > 1)
			r2 = hasFloatInOpr(opr->opr.op[1]);
		if (r1 != r2)
			return 1;
	} else if (opr->type == typeFloat)
		return 1;
	else if (opr->type == typeId){
		if (opr->id.tipo == typeFloat)
			return 1;
	}
}

int getNumItems(Item *i){
	int cont = 0;
	while(i != NULL){
		cont++;
		i = i->prox;
	}
	return cont;
}

void printAfterIf(FILE *f){
	fprintf(f, "iconst_0\n");
	fprintf(f, "goto L%d\n", label_cont+1);
	fprintf(f, "L%d:\n", label_cont);
	label_cont++;
	fprintf(f, "iconst_1\n");
	fprintf(f, "L%d:\n", label_cont);
	label_cont++;
}

void printParametros(Item *prms, FILE *f){
	// printf("%s ", getIdTipo(prms->arv->id.tipo));
	// printf("%s", prms->arv->id.name);

	if (prms->prox != NULL){
		// printf(", ");
		printParametros(prms->prox, f);
	}
}

void printVariaveis(Item *vars, FILE *f){
	// printf("%s", vars->arv->id.name);

	if (vars->prox != NULL){
		// printf(", ");
		printVariaveis(vars->prox, f);
	}
}

void printDeclaracao(Declaracao *decl, FILE *f){
	Item *var = decl->vars;
	while(var != NULL){
		if (decl->tipo == typeString){
			fprintf(f, "ldc \"\"\n");
			fprintf(f, "astore_%d\n", var->arv->id.i+isMain);
		} else if (decl->tipo == typeInt){
			fprintf(f, "ldc 0\n");
			fprintf(f, "istore_%d\n", var->arv->id.i+isMain);
		} else if (decl->tipo == typeFloat){
			fprintf(f, "ldc 0.0\n");
			fprintf(f, "fstore_%d\n", var->arv->id.i+isMain);
		}
		var = var->prox;
	}
	// printf("%s ", getIdTipo(decl->tipo));
	// printVariaveis(decl->vars, f);
	// printf(";\n");
}

void printDeclaracoes(ListaDecl *decl, FILE *f){
	printDeclaracao(decl->decl, f);
	if (decl->prox != NULL)
		printDeclaracoes(decl->prox, f);
}

void printNo(tipoNo *cmd, FILE *f){
	int temp;
	switch(cmd->type){
		case typeInt:
			fprintf(f, "ldc %d\n", cmd->inteiro.val);
			break;
		case typeFloat:
			fprintf(f, "ldc %f\n", cmd->real.val);
			break;
		case typeString:
			fprintf(f, "ldc %s\n", cmd->string.str);
			break;
		case typeId:
			switch (cmd->id.tipo){
				case typeInt:
					fprintf(f, "iload_%d\n", cmd->id.i+isMain);
					break;
				case typeFloat: 
					fprintf(f, "fload_%d\n", cmd->id.i+isMain);
					break;
				case typeString:
					fprintf(f, "aload_%d\n", cmd->id.i+isMain);
					break;
			}
			break;
		case typeOpr:
			switch(cmd->opr.opr){
				case 1: // Chama Função
					if(cmd->opr.op[1])
						printNo(cmd->opr.op[1], f);
					fprintf(f, "invokestatic output/%s", cmd->opr.op[0]->id.name);
					Funcao* funcao = malloc(sizeof(Funcao));
					if (funcao == NULL){
						printf("Erro ao alocar memória para a busca de função\n");
						exit(1);
					}
					funcao = searchFuncoes(cmd->opr.op[0]->id.name);
					Item* prm = funcao->prms;
					fprintf(f, "(");
					while(prm != NULL){
						if (prm->arv->id.tipo == typeInt)
							fprintf(f, "I");
						else if (prm->arv->id.tipo == typeFloat)
							fprintf(f, "F");
						else if (prm->arv->id.tipo == typeString)
							fprintf(f, "Ljava/lang/String;");
						prm = prm->prox;
					}
					fprintf(f, ")");
					if (funcao->no->id.tipo == typeInt)
							fprintf(f, "I");
						else if (funcao->no->id.tipo == typeFloat)
							fprintf(f, "F");
						else if (funcao->no->id.tipo == typeString)
							fprintf(f, "Ljava/lang/String;");
						else if (funcao->no->id.tipo == typeVoid)
							fprintf(f, "V");
					fprintf(f, "\n");
					break;
				case 2: // Parâmetros da Função
					printNo(cmd->opr.op[0], f);
					if (cmd->opr.op[1])
						printNo(cmd->opr.op[1], f);
					break;
				case SIM_ADICAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (hasFloatInOpr(cmd->opr.op[0]))
						fprintf(f, "fadd\n");
					else 
						fprintf(f, "iadd\n");
					break;
				case SIM_MULTIPLICACAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (hasFloatInOpr(cmd->opr.op[0]))
						fprintf(f, "fmul\n");
					else 
						fprintf(f, "imul\n");
					break;
				case SIM_SUBTRACAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (hasFloatInOpr(cmd->opr.op[0]))
						fprintf(f, "fsub\n");
					else 
						fprintf(f, "isub\n");
					break;
				case SIM_DIVISAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (hasFloatInOpr(cmd->opr.op[0]))
						fprintf(f, "fdiv\n");
					else 
						fprintf(f, "idiv\n");
					break;
				case SIM_IGUAL:
					printNo(cmd->opr.op[1], f);
					if (cmd->opr.op[0]->id.tipo == typeString)
						fprintf(f, "astore_%d\n", cmd->opr.op[0]->id.i+isMain);
					else if (cmd->opr.op[0]->id.tipo == typeInt)
						fprintf(f, "istore_%d\n", cmd->opr.op[0]->id.i+isMain);
					else if (cmd->opr.op[0]->id.tipo == typeFloat)
						fprintf(f, "fstore_%d\n", cmd->opr.op[0]->id.i+isMain);
					break;
				case SIM_IGUALIGUAL:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpeq L%d\n", label_cont);
					else {
						fprintf(f, "fcmpg\n");
						printNo(cmd->opr.op[0], f);
						printNo(cmd->opr.op[1], f);
						fprintf(f, "fcmpl\n");
						fprintf(f, "ifge L%d\n", label_cont);
					}
					printAfterIf(f);
					break;
				case SIM_DIFERENTE:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpne L%d\n", label_cont);
					else
						fprintf(f, "fcmpg\n");
						printNo(cmd->opr.op[0], f);
						printNo(cmd->opr.op[1], f);
						fprintf(f, "fcmpl\n");
						fprintf(f, "ifne L%d\n", label_cont);
					printAfterIf(f);
					break;
				case SIM_MAIORQUE:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1])){
						fprintf(f, "if_icmpgt L%d\n", label_cont);
					} else {
						fprintf(f, "fcmpg\n");
						fprintf(f, "ifge L%d\n", label_cont);
					}
					printAfterIf(f);
					break;
				case SIM_MENORQUE:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmplt L%d\n", label_cont);
					else{
						fprintf(f, "fcmpl\n");
						fprintf(f, "ifge L%d\n", label_cont);
					}
					printAfterIf(f);
					break;
				case SIM_MAIOROUIGUAL:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpge L%d\n", label_cont);
					else {
						fprintf(f, "fcmpg\n");
						fprintf(f, "ifge L%d\n", label_cont);
					}
					printAfterIf(f);
					break;
				case SIM_MENOROUIGUAL:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmple L%d\n", label_cont);
					else {
						fprintf(f, "fcmpl\n");
						fprintf(f, "ifge L%d\n", label_cont);
					}
					printAfterIf(f);
					break;
				case SIM_E:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					fprintf(f, "and\n");
					break;
				case SIM_OU:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					fprintf(f, "or\n");
					break;
				case SIM_NEGACAO:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					printAfterIf(f);
					break;
				case COM_RETORNO:
					if (cmd->opr.op[0] != NULL)
						printNo(cmd->opr.op[0], f);
					if (isMain){
						fprintf(f, "return\n");
					} else {
						if (tipoFuncaoAtual == typeInt)
							fprintf(f, "ireturn\n");
						else if (tipoFuncaoAtual == typeFloat)
							fprintf(f, "freturn\n");
						else if (tipoFuncaoAtual == typeString)
							fprintf(f, "areturn\n");
					}
					break;
				case COM_SE:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					int temp = label_cont;
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "L%d:\n", label_cont);
					break;
				case COM_SENAO:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					temp = label_cont;
					label_cont++;
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d\n", label_cont);
					fprintf(f, "L%d:\n", temp);
					printComandos(cmd->opr.rep->senao, f);
					fprintf(f, "L%d:\n", label_cont);
					break;
				case COM_ENQUANTO:
					fprintf(f, "L%d:\n", label_cont);
					temp = label_cont;
					label_cont++;
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d\n", temp);
					fprintf(f, "L%d:\n", label_cont);
					break;
				case COM_IMPRIME:
					printNo(cmd->opr.op[0], f);
					if (cmd->opr.op[0]->type == typeString)
						fprintf(f, "invokestatic output/output_str(Ljava/lang/String;)V\n");
					else if (cmd->opr.op[0]->type == typeInt)
						fprintf(f, "invokestatic output/output_int(I)V\n");
					else if (cmd->opr.op[0]->type == typeFloat)
						fprintf(f, "invokestatic output/output_float(F)V\n");
					else if (cmd->opr.op[0]->type == typeId){
						if (cmd->opr.op[0]->id.tipo == typeString)
							fprintf(f, "invokestatic output/output_str(Ljava/lang/String;)V\n");
						else if (cmd->opr.op[0]->id.tipo == typeInt)
							fprintf(f, "invokestatic output/output_int(I)V\n");
						else if (cmd->opr.op[0]->id.tipo == typeFloat)
							fprintf(f, "invokestatic output/output_float(F)V\n");
					} else if (cmd->opr.op[0]->type == typeOpr){
						if (hasFloatInOpr(cmd->opr.op[0]))
							fprintf(f, "invokestatic output/output_float(F)V\n");
						else if (!hasFloatInOpr(cmd->opr.op[0]))
							fprintf(f, "invokestatic output/output_int(I)V\n");
					}
					break;
				case COM_LER:
					// printf("read(");
					// printNo(cmd->opr.op[0], f);
					// printf(")");
					break;
				case COM_PARA:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "L%d:\n", label_cont);
					temp = label_cont;
					label_cont++;
					printNo(cmd->opr.op[1], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					printNo(cmd->opr.op[2], f);
					fprintf(f, "goto L%d\n", temp);
					fprintf(f, "L%d:\n", label_cont);
					label_cont++;
					break;
				case COM_FACA:
					fprintf(f, "L%d:\n", label_cont);
					temp = label_cont;
					label_cont++;
					printComandos(cmd->opr.rep->cmds, f);
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					fprintf(f, "goto L%d\n", temp);
					fprintf(f, "L%d:\n", label_cont);
					label_cont++;
					break;
			}
			break;
	}
}

void printComandos(Item *cmds, FILE *f){
	printNo(cmds->arv, f);
	// printf(";\n");
	if (cmds->prox != NULL)
		printComandos(cmds->prox, f);
}

void printBloco(Bloco *blc, FILE *f){
	// printf("{\n");
	if (blc->decl)
		printDeclaracoes(blc->decl, f);
	if (blc->cmds)
		printComandos(blc->cmds, f);
	// printf("}\n");
}

void printFuncao(Funcao *f, FILE *file){
	tipoFuncaoAtual = f->no->id.tipo;
    if (!strcmp(f->no->id.name, "main")){
        fprintf(file, ".method public static main([Ljava/lang/String;)V\n.limit locals 100\n.limit stack 100\n");
		isMain = 1;
	} else {
        fprintf(file, ".method public static %s(", f->no->id.name);
		Item* prm = f->prms; 
		while(prm != NULL){
			if (prm->arv->id.tipo == typeInt)
				fprintf(file, "I");
			else if (prm->arv->id.tipo == typeFloat)
				fprintf(file, "F");
			else if (prm->arv->id.tipo == typeString)
				fprintf(file, "Ljava/lang/String;");
			prm = prm->prox;
		}
		fprintf(file, ")");
		if (f->no->id.tipo == typeInt)
				fprintf(file, "I");
			else if (f->no->id.tipo == typeFloat)
				fprintf(file, "F");
			else if (f->no->id.tipo == typeString)
				fprintf(file, "Ljava/lang/String;");
			else if (f->no->id.tipo == typeVoid)
				fprintf(file, "V");
		fprintf(file, "\n");
        fprintf(file, ".limit locals 100\n");
        fprintf(file, ".limit stack 100\n");
    }
	if (f->prms != NULL)
		printParametros(f->prms, file);
	if (f->blc != NULL)
		printBloco(f->blc, file);
	fprintf(file, ".end method\n\n");
	if (f->prox != NULL)
		printFuncao(f->prox, file);
}

void printPrograma(Funcao *fun){
	tbl_funcoes = malloc(sizeof(Funcao));
	if (tbl_funcoes == NULL){
		printf("Erro ao alocar memória para a tabela de funções\n");
		exit(1);
	}
	tbl_funcoes = fun;
	label_cont = 0;
	isMain = 0;
	
    FILE *f = fopen("Jasmin/output.j", "w");
    // write_code(concat(".source ", source_file");
	fprintf(f, ".class public output\n.super java/lang/Object\n.method public <init>()V\naload_0\ninvokenonvirtual java/lang/Object/<init>()V\nreturn\n.end method\n\n");

    fprintf(f, ".method public static output_int(I)V\n.limit locals 5\n.limit stack 5\ngetstatic java/lang/System/out Ljava/io/PrintStream;\niload_0\ninvokevirtual java/io/PrintStream/print(I)V\nreturn\n.end method\n\n.method public static output_float(F)V\n.limit locals 5\n.limit stack 5\ngetstatic java/lang/System/out Ljava/io/PrintStream;\nfload 0  ; the argument to function\ninvokevirtual java/io/PrintStream/print(F)V\nreturn\n.end method\n\n.method public static output_str(Ljava/lang/String;)V\n.limit locals 5\n.limit stack 5\ngetstatic java/lang/System/out Ljava/io/PrintStream;\naload 0\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\nreturn\n.end method\n\n");
    printFuncao(fun, f);
    fclose(f);
}