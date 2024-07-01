#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jasmin.h"
#include "../tipoNo.h"
#include "../expr.tab.h"

int label_cont;

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
			fprintf(f, "astore_%d\n", var->arv->id.i+1);
		} else if (decl->tipo == typeInt){
			fprintf(f, "ldc 0\n");
			fprintf(f, "istore_%d\n", var->arv->id.i+1);
		} else if (decl->tipo == typeFloat){
			fprintf(f, "ldc 0.0\n");
			fprintf(f, "fstore_%d\n", var->arv->id.i+1);
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
					fprintf(f, "iload_%d\n", cmd->id.i+1);
					break;
				case typeFloat: 
					fprintf(f, "fload_%d\n", cmd->id.i+1);
					break;
				case typeString:
					fprintf(f, "aload_%d\n", cmd->id.i+1);
					break;
			}
			break;
		case typeOpr:
			switch(cmd->opr.opr){
				case 1: // Chama Função
					if(cmd->opr.op[1])
						printNo(cmd->opr.op[1], f);
					fprintf(f, "invokestatic output/%s", cmd->opr.op[0]->id.name);
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
						fprintf(f, "astore_%d\n", cmd->opr.op[0]->id.i+1);
					else if (cmd->opr.op[0]->id.tipo == typeInt)
						fprintf(f, "istore_%d\n", cmd->opr.op[0]->id.i+1);
					else if (cmd->opr.op[0]->id.tipo == typeFloat)
						fprintf(f, "fstore_%d\n", cmd->opr.op[0]->id.i+1);
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
					if (cmd->opr.op[0] != NULL)
						printNo(cmd->opr.op[0], f);
					break;
				case COM_SE:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "L%d:", label_cont);
					break;
				case COM_SENAO:
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
					temp = label_cont;
					label_cont++;
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d\n", label_cont);
					fprintf(f, "L%d:", temp);
					printComandos(cmd->opr.rep->senao, f);
					fprintf(f, "L%d:", label_cont);
					break;
				case COM_ENQUANTO:
					fprintf(f, "L%d:", label_cont);
					printNo(cmd->opr.op[0], f);
					temp = label_cont;
					label_cont++;
					fprintf(f, "ifeq L%d\n", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d\n", temp);
					fprintf(f, "L%d:", label_cont);
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
					fprintf(f, "L%d:", label_cont);
					printNo(cmd->opr.op[1], f);
					temp = label_cont;
					label_cont++;
					fprintf(f, "ifeq L%d\n", label_cont);
					printNo(cmd->opr.op[2], f);
					printComandos(cmd->opr.rep->cmds, f);
					fprintf(f, "goto L%d\n", temp);
					fprintf(f, "L%d:", label_cont);
					break;
				case COM_FACA:
					fprintf(f, "L%d:", label_cont);
					printComandos(cmd->opr.rep->cmds, f);
					printNo(cmd->opr.op[0], f);
					fprintf(f, "ifeq L%d\n", label_cont);
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
    if (!strcmp(f->no->id.name, "main")){
        fprintf(file, ".method public static main([Ljava/lang/String;)V\n.limit locals 100\n.limit stack %d\n", getNumItems(f->syms)+1);
    } else {
        // hashmap_set(fun_map, f->no->id.name, (void*) f);
        // id_map = hashmap_create(HASHMAP_BUCKET_SZ);
        // int id_cont = getNumItems(f->prms);
        // fprintf(".method public static %s", f->no->id.name);
        // for (int i = 0; i < vector_size(f->prms); i++) {
        //     symbol* smb = vector_get(fun->params, i);
        //     hashmap_set(id_map, smb->id, (void*) smb);
        // }
        // write_code("\t.limit locals %d", getNumItems(f->tbl->syms));
        // write_code("\t.limit stack 100");
    }
	// printf("%s ", getIdTipo(f->no->id.tipo));
	// printf("%s", f->no->id.name);
	
	// printf("(");
	if (f->prms != NULL)
		printParametros(f->prms, file);
	// printf(")");

	if (f->blc != NULL)
		printBloco(f->blc, file);
	if (!strcmp(f->no->id.name, "main")){
		fprintf(file, "return\n");
	} else {
		if (f->no->id.tipo == typeInt)
			fprintf(file, "ireturn\n");
		else if (f->no->id.tipo == typeFloat)
			fprintf(file, "freturn\n");
		else if (f->no->id.tipo == typeString)
			fprintf(file, "areturn\n");
	}
	fprintf(file, ".end method\n\n");
	if (f->prox != NULL)
		printFuncao(f->prox, file);
}

void printPrograma(Funcao *fun){
	label_cont = 0;
	
    FILE *f = fopen("Jasmin/output.j", "w");
    // write_code(concat(".source ", source_file");
	fprintf(f, ".class public output\n.super java/lang/Object\n.method public <init>()V\naload_0\ninvokenonvirtual java/lang/Object/<init>()V\nreturn\n.end method\n\n");

    fprintf(f, ".method public static output_int(I)V\n.limit locals 5\n.limit stack 5\ngetstatic java/lang/System/out Ljava/io/PrintStream;\niload_0\ninvokevirtual java/io/PrintStream/print(I)V\nreturn\n.end method\n\n.method public static output_float(F)V\n.limit locals 5\n.limit stack 5\ngetstatic java/lang/System/out Ljava/io/PrintStream;\nfload 0  ; the argument to function\ninvokevirtual java/io/PrintStream/print(F)V\nreturn\n.end method\n\n.method public static output_str(Ljava/lang/String;)V\n.limit locals 5\n.limit stack 5\ngetstatic java/lang/System/out Ljava/io/PrintStream;\naload 0\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\nreturn\n.end method\n\n");
    printFuncao(fun, f);
    fclose(f);
}