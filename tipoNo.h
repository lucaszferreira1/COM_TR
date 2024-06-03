#ifndef TIPONO_H
#define TIPONO_H

typedef enum {typeInt, typeFloat, typeString, typeId, typeOpr} eTipo;

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
    struct tagTipoNo *op[1]; // Operandos
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

#endif
