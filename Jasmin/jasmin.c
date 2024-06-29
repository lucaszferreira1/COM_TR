#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.tab.h"
#include "tipoNo.h"

int id_cont, label_cont;

int hasFloatInOpr(tipoNo *opr){
	int r1, r2;
	if (opr->type == typeOpr){
		r1 = hasFloatInOpr(opr->opr.op[0]);
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
	fprintf(f, "goto L%d", label_cont);
	fprintf(f, "L:%d\n", label_cont);
	label_cont++;
	fprintf(f, "iconst_1\n");
	fprintf(f, "L:%d\n", label_cont);
	label_cont++;
}

void printParametros(Item *prms, FILE *f){
	printf("%s ", getIdTipo(prms->arv->id.tipo));
	printf("%s", prms->arv->id.name);

	if (prms->prox != NULL){
		printf(", ");
		printParametros(prms->prox, f);
	}
}

void printVariaveis(Item *vars, FILE *f){
	printf("%s", vars->arv->id.name);

	if (vars->prox != NULL){
		printf(", ");
		printVariaveis(vars->prox, f);
	}
}

void printDeclaracao(Declaracao *decl, FILE *f){
	printf("%s ", getIdTipo(decl->tipo));
	printVariaveis(decl->vars, f);
	printf(";\n");
}

void printDeclaracoes(ListaDecl *decl, FILE *f){
	printDeclaracao(decl->decl, f);
	if (decl->prox != NULL)
		printDeclaracoes(decl->prox, f);
}

void printNo(tipoNo *cmd, FILE *f){
	
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
					fprintf(f, "iload %d\n", cmd->id.i);
					break;
				case typeFloat: 
					fprintf(f, "fload %d\n", cmd->id.i);
					break;
				case typeString:
					fprintf(f, "aload %d\n", cmd->id.i);
					break;
			}
			break;
		case typeOpr:
			switch(cmd->opr.opr){
				case 1: // Chama Função
					if(cmd->opr.op[1])
						printNo(cmd->opr.op[1], f);
					fprintf(f, "invokestatic output/%s", cmd->opr.op[0]->id.name);
					// printNo(cmd->opr.op[0]);
					// printf("(");
					// if (cmd->opr.op[1]){	
					// 	printNo(cmd->opr.op[1]);
					// }
					// printf(")");
					break;
				case 2: // Parâmetros da Função
					printNo(cmd->opr.op[0], f);
					if (cmd->opr.op[1]){
						// printf(", ");
						printNo(cmd->opr.op[1], f);
					}
					break;
				case SIM_ADICAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					fprintf(f, "add\n");
					break;
				case SIM_MULTIPLICACAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					fprintf(f, "mul\n");
					break;
				case SIM_SUBTRACAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					printf(f, "sub\n");
					break;
				case SIM_DIVISAO:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					printf(f, "div\n");
					break;
				case SIM_IGUAL://
					printNo(cmd->opr.op[0], f);
					printf("=");
					printNo(cmd->opr.op[1], f);
					break;
				case SIM_IGUALIGUAL:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpeq L%d\n", label_cont);
					else
						fprintf(f, "if_ifeq L%d\n", label_cont);
					printAfterIf(f);
					break;
				case SIM_DIFERENTE:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpne L%d\n", label_cont);
					else
						fprintf(f, "if_ifne L%d\n", label_cont);
					printAfterIf(f);
					break;
				case SIM_MAIORQUE:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpgt L%d\n", label_cont);
					else
						fprintf(f, "if_ifgt L%d\n", label_cont);
					printAfterIf(f);
					break;
				case SIM_MENORQUE:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmplt L%d\n", label_cont);
					else
						fprintf(f, "if_iflt L%d\n", label_cont);
					printAfterIf(f);
					break;
				case SIM_MAIOROUIGUAL:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmpge L%d\n", label_cont);
					else
						fprintf(f, "if_ifge L%d\n", label_cont);
					printAfterIf(f);
					break;
				case SIM_MENOROUIGUAL:
					printNo(cmd->opr.op[0], f);
					printNo(cmd->opr.op[1], f);
					if (!hasFloatInOpr(cmd->opr.op[0]) && !hasFloatInOpr(cmd->opr.op[1]))
						fprintf(f, "if_icmple L%d\n", label_cont);
					else
						fprintf(f, "if_ifle L%d\n", label_cont);
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
					fprintf(f, "if_ifeq L%d\n", label_cont);
					printAfterIf(f);
					break;
				case COM_RETORNO:
					if (cmd->opr.op[0] != NULL){
						printNo(cmd->opr.op[0], f);
						if (cmd->opr.op[0]->type == typeInt || cmd->opr.op[0]->id.tipo == typeInt)
							fprintf(f, "ireturn\n");
						else if (cmd->opr.op[0]->type == typeFloat || cmd->opr.op[0]->id.tipo == typeFloat)
							fprintf(f, "freturn\n");
						else if (cmd->opr.op[0]->type == typeString || cmd->opr.op[0]->id.tipo == typeString)
							fprintf(f, "areturn\n");
					} else {
						fprintf(f, "return\n");
					}
					break;
				case COM_SE:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L\n", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "L%d:", label_cont);
					break;
				case COM_SENAO:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L\n", label_cont);
					int temp = label_cont;
					label_cont++;
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d\n", label_cont);
					fprintf(f, "L%d:", temp);
					printComandos(cmd->opr.rep->senao, f);
					fprintf(f, "L%d:", label_cont);
					break;
				case COM_ENQUANTO:
					printNo(cmd->opr.op[0], f);
					fprintf("L%d:", label_cont);
					int temp = label_cont;
					label_cont++;
					fprintf(f, "ifeq L%d\n", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d", temp);
					fprintf(f, "L%d:", label_cont);
					break;
				case COM_IMPRIME:
					printNo(cmd->opr.op[0], f);
					if (cmd->opr.op[0]->type == typeString)
						fprintf(f, "invokestatic output/Verb/output_str(Ljava/lang/String;)V")
					printf("print(");
					printNo(cmd->opr.op[0], f);
					printf(")");
					break;
				case COM_LER:
					printf("read(");
					printNo(cmd->opr.op[0], f);
					printf(")");
					break;
				case COM_PARA:
					printf("for(");
					printNo(cmd->opr.op[0], f);
					printf(";");
					printNo(cmd->opr.op[1], f);
					printf(";");
					printNo(cmd->opr.op[2], f);
					printf("){\n");
					printComandos(cmd->opr.rep->cmds, f);
					printf("}");
				case COM_FACA:
					printf("do{\n");
					printComandos(cmd->opr.rep->cmds, f);
					printf("}while(");
					printNo(cmd->opr.op[0], f);
					printf(")");
			}
			break;
	}
}

void printComandos(Item *cmds, FILE *f){
	printNo(cmds->arv, f);
	printf(";\n");
	if (cmds->prox != NULL)
		printComandos(cmds->prox, f);
}

void printBloco(Bloco *blc, FILE *f){
	printf("{\n");
	if (blc->decl)
		printDeclaracoes(blc->decl, f);
	if (blc->cmds)
		printComandos(blc->cmds, f);
	printf("}\n");
}

void printFuncao(Funcao *f, FILE *file){
    if (!strcmpr(f->no->id.name, "main")){
        fprintf(file, "
        .method public static main([Ljava/lang/String;)V
        .limit locals 8\n
		.limit stack %d
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
		printParametros(f->prms, file);
	printf(")");

	if (f->blc != NULL)
		printBloco(f->blc, file);
	
    if (!strcmp(f->no->id.name, "main")){
        fprintf(file, "
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
		printFuncao(f->prox, file);
}

void printPrograma(Funcao *fun){
	label_cont = 0;
	id_cont = 0;
    FILE *f = fopen("output.j", "w");
    // write_code(concat(".source ", source_file");
	fprintf(f, "
    .class public output\n.super java/lang/Object\n
	.method public <init>()V
		aload_0
		invokenonvirtual java/lang/Object/<init>()V
		return
	.end method\n
    ");

    fprintf(f, "
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
    printFuncao(fun, f);
    fclose(f);
}