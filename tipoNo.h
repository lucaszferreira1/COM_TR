#ifndef TIPONO_H
#define TIPONO_H

typedef enum {typeInt, typeFloat, typeString, typeVoid, typeId, typeOpr} eTipo;

typedef struct{
    int val;
} intTipoNo;

typedef struct{
    float val;
} floatTipoNo;

typedef struct{
    char *str;
} stringTipoNo;

typedef struct{
    char *name; // Nome da Variavel
    eTipo tipo; // Tipo da Variavel
    int i;
} idTipoNo;

typedef struct{
    int opr; // Operacao
    int nOps; // Numero de operandos
    struct tagTipoNo **op; // Operandos
    struct repeticao *rep;
} oprTipoNo;

typedef struct tagTipoNo{
    eTipo type;

    union{
        intTipoNo inteiro;
        floatTipoNo real;
        stringTipoNo string;
        idTipoNo id;
        oprTipoNo opr;
    };
} tipoNo;

typedef struct Item{
    struct Item *prox;
    tipoNo *arv;
}Item;

typedef struct repeticao{
    Item *cmds;
    Item *senao;
}Repeticao;

typedef struct Declaracao{
    eTipo tipo; // Tipo
    Item *vars; // Variaveis
}Declaracao;

typedef struct ListaDecl{
    struct ListaDecl *prox; // Proxima declaracao na lista
    Declaracao *decl; // Declaracao
}ListaDecl;

typedef struct Bloco{
    ListaDecl *decl; // Declaracoes
    Item *cmds; // Comandos
}Bloco;

typedef struct Funcao{
    struct Funcao *prox; // Proxima funcao na lista
    int i;
    eTipo tipo; // Tipo
    char *name; // Nome
    Item *syms; // Simbolos
    Item *prms; // Parametros
    Bloco *blc; // Bloco
}Funcao;

#endif
