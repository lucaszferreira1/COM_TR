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
    int tipo; // Tipo da Variavel
} idTipoNo;

typedef struct{
    int opr; // Operacao
    int nOps; // Numero de operandos
    struct tagTipoNo *op[4]; // Operandos
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

typedef struct Declaracao{
    eTipo tipo;
    Item *vars;
}Declaracao;

typedef struct ListaDecl{
    struct ListaDecl *prox;
    Declaracao *decl;
}ListaDecl;

typedef struct Bloco{
    ListaDecl *decl;
    Item *cmds;
}Bloco;

typedef struct Funcao{
    eTipo tipo; // Tipo
    char *name; // Nome
    Item *syms; // Simbolos
    Item *prms; // Parametros
    Bloco *blc;
}Funcao;

#endif
