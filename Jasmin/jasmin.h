#ifndef JASMIN_H
#define JASMIN_H

#include <stdio.h>
#include <stdlib.h>
#include "../tipoNo.h"
#include "../expr.tab.h"

int hasFloatInOpr(tipoNo *opr);
int getNumItems(Item *i);
void printAfterIf(FILE *f);
void printParametros(Item *prms, FILE *f);
void printVariaveis(Item *vars, FILE *f);
void printDeclaracao(Declaracao *decl, FILE *f);
void printDeclaracoes(ListaDecl *decl, FILE *f);
void printNo(tipoNo *cmd, FILE *f);
void printComandos(Item *cmds, FILE *f);
void printBloco(Bloco *blc, FILE *f);
void printFuncao(Funcao *f, FILE *file);
void printPrograma(Funcao *fun);

#endif