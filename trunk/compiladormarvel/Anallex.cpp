/**
 * 
 *          Analisador L�xico
 * 
 */
#include "Anallex.h"
#include "Tokens.h"
#include "Erro.h"
#include "TabSimbolos.h"
#include <ctype.h>
#include <stdio.h>

char proxCaractere();
void limpaLexema();
void concatenaLexema(char caractere);
void devolveCaractere();
char *retornaLexema();
int insereTabSimbolos(int, char*);
REGISTRO *buscaTabSimbolos(char*);
void inicializaBuffer(char *);
void finalizaBuffer();

/* Vari�vel que define a linha lida */
int linha = 1;

/* Fun��o de reconhecimento de token */
/* A fun��o retorna um inteiro referente a um token especificado em tokens.h */
int proxToken(){
    int state = 0;
    char c;

    // Executa um loop infinito enquanto n�o executa return
    while (1) {
        c = proxCaractere();
        switch (state) {                                     // Faz um case entre os states poss�veis
            case 0:                                          // Estado inicial
                limpaLexema();
                if (c == SPACE || c == TAB || c == RETURN)   // Verifica se � caracter vazio
                    state = 0;                               // O state continua sendo inicial
                else if (c == LINE) {                        // Se nova linha, incrementa linha
                    linha++;
                    state = 0;
                }
                // Sen�o o pr�ximo state deve ser definido conforme
				// qualquer uma das situa��es abaixo
                else if (isdigit(c)){
                    concatenaLexema(c);
                    state = 1;
                }
                else if (isalpha(c)) {                       // Verifica se o caracter lido � uma letra
                    concatenaLexema(c);
                    state = 39;
                }
                // Verifica se o caracter lido � um s�mbolo
                else if (c == '!') state = 10;
                else if (c == '=') state = 13;
                else if (c == '<') state = 16;
                else if (c == '>') state = 19;
                else if (c == '|') state = 22;
                else if (c == '&') state = 25;
                else if (c == '{') state = 43;
                else if (c == '"'){
                    concatenaLexema(c);
                    state = 41;
                }
                // Verifica se o caracter lido � um s�mbolo simples que retorna token
                else {
                    state = 0; 
                    if (c == EOF) return EOF;
                    if (c == '[') return OPENBRA;
                    if (c == ']') return CLOSEBRA;
                    if (c == ',') return COMMA;
                    if (c == '(') return OPENPAR;
                    if (c == ')') return CLOSEPAR;
                    if (c == '+') return PLUS;
                    if (c == '-') return MINUS;
                    if (c == '*') return MULT;
                    if (c == '/') return DIV;
                    if (c == '%') return MOD;
                    if (c == ';') return SMCLN;
                    emiteErroLexico(ERRO_GETTOKEN, linha);   // Outra transi��o - ERRO DE TOKEN
                }
                break;
            case 1:
                concatenaLexema(c);
                if (isdigit(c))    state = 1;
                else if (c == '.') state = 2;                // Verifica se � ponto - n�mero decimal
                else if ((c == 'E') || (c == 'e')) state = 4;// Verifica se � E - n�mero real
                else {                                       // Outra transi��o - state final 7
                    state = 0;
                    devolveCaractere();

                    insereTabSimbolos(NUM, retornaLexema());
                    return NUM;
                }
                break;
            case 2:
                concatenaLexema(c);
                if (isdigit(c))   state = 3;
                else {                                       // Outra transi��o - ERRO DE DECIMAL
                    state = 0;
                    devolveCaractere();
                    
                    insereTabSimbolos(NUM, retornaLexema());
                    return NUM;                              // Retorna o token NUM
                }
                break;
            case 3:
                concatenaLexema(c);
                if (isdigit(c))    state = 3;
                else if (c == 'E') state = 4;                // Verifica se � E - continua��o do n�mero real
                else {                                       // Outra transi��o - state final 8
                    state = 0;
                    devolveCaractere();

                    insereTabSimbolos(NUM, retornaLexema());
                    return NUM;                              // Retorna o token NUM
                }
                break;
            case 4:
                concatenaLexema(c);
                if (isdigit(c))                state = 6;
                else if (c == '+' || c == '-') state = 5;    // Verifica se � continua��o de n�mero real
                else {                                       // Outra transi��o - ERRO DE REAL
                    state = 0;                               // Seta o state como inicial para analisar o pr�ximo c

                    emiteErroLexico(ERRO_NUM_REAL,linha);
                    devolveCaractere();
                }
                break;
            case 5:
                concatenaLexema(c);
                if (isdigit(c)) state = 6;
                else {                                       // Outra transi��o - ERRO DE REAL
                    state = 0;                               // Seta o state como inicial para analisar o pr�ximo c

                    emiteErroLexico(ERRO_NUM_REAL,linha);
                    devolveCaractere();
                }
                break;
            case 6:
                concatenaLexema(c);
                if (isdigit(c)) state = 6;
                else {                                       // Outra transi��o - state final 9
                    state = 0;
                    devolveCaractere();
                    
                    insereTabSimbolos(NUM, retornaLexema());
                    return NUM;                              // Retorna o token NUM
                }
                break;                           
            case 10:
                state = 0;
                if (c == '=') return NE;                     // Verifica se � rela��o NOT EQUAL
                else {                                       // Caso contr�rio � apenas NOT
                    devolveCaractere();
                    return NOT;                              // Retorna o token
                }
                break;        
            case 13:
                state = 0;
                if (c == '=') return EQUALS;                 // Verifica se � rela��o EQUALS
                else {                                       // Caso contr�rio � apenas ASSIGN
                    devolveCaractere();
                    return ASSIGN;                           // Retorna o token
                }
                break;        
            case 16:
                state = 0;
                if (c == '=') return LE;                     // Verifica se � rela��o LE
               else {                                        // Caso contr�rio � apenas LT
                    devolveCaractere();
                    return LT;                               // Retorna o token
                }
                break;        
            case 19:
                state = 0;
                if (c == '=') return GE;                     // Verifica se � rela��o GE
                else {                                       // Caso contr�rio � apenas GT
                    devolveCaractere();
                    return GT;                               // Retorna o token
                }
                break;        
            case 22:
                state = 0;
                if (c == '|') return OR;                     // Verifica se � rela��o OR
                else {                                       // Caso contr�rio � apenas BITOR
                    devolveCaractere();
                    return BITOR;                            // Retorna o token
                }
                break;        
            case 25:
                state = 0;
                if (c == '&') return AND;                    // Verifica se � rela��o AND
                else {                                       // Caso contr�rio � apenas BITAND
                    devolveCaractere();
                    return BITAND;                           // Retorna o token
                }
                break;        
            case 39:
                concatenaLexema(c);
                if (!isalnum(c)) {
                    state = 0;                      
                    devolveCaractere();
                    if (!insereTabSimbolos(ID, retornaLexema())) return buscaTabSimbolos(retornaLexema())->token;
                    return ID;                               // Retorna o token e seu valor
                }
                break;        
            case 41:
                concatenaLexema(c);
                if (c == '"') { 
                    state = 0;
                    
                    insereTabSimbolos(LITERAL, retornaLexema());
                    return LITERAL;                          // Caracter de fim de literal - state final 33
                }
                if (c == EOF) {                              // Fim de arquivo no meio de uma literal
                    emiteErroLexico(ERRO_EOF_LITERAL,linha);
                    return EOF;
                }
                break;        
            case 43:
                if (c == '}') state = 0; 
                else if (c == EOF) {                                          
                    emiteErroLexico(ERRO_EOF_COMENTARIO,linha);
                    return EOF;
                }
        }// end case
    }// end while
}// end proxToken

/*
 * Fun��o que imprime o token
 */
void emitirToken(int token, char *atributo){
    if ((token == ID) || (token == LITERAL) || (token == NUM))
        printf("%s.%s\n", retornaToken(token), atributo);
    else printf("%s\n", retornaToken(token));
}

/*
 * Retorna os caracteres correspondentes ao valor numerico do token
 */
char *retornaToken(int token) {
    switch(token) {
        case FLOAT:           return("FLOAT");
        case INTEGER:         return("INTEGER");
        case PARAM:           return("PARAM");
        case VECTOR:          return("VECTOR");
        case NUM:             return("NUM");
        case ID:              return("ID");
        case FRAGMENT:        return("FRAGMENT");
        case OPENBRA:         return("OPENBRA");
        case CLOSEBRA:        return("CLOSEBRA");
        case COMMA:           return("COMMA");
        case ASSIGN:          return("ASSIGN");
        case OPENPAR:         return("OPENPAR");
        case CLOSEPAR:        return("CLOSEPAR");
        case NOT:             return("NOT");
        case PLUS:            return("PLUS");
        case MINUS:           return("MINUS");
        case EQUALS:          return("EQUALS");
        case LT:              return("LT");
        case LE:              return("LE");
        case GE:              return("GE");
        case GT:              return("GT");
        case NE:              return("NE");
        case BITOR:           return("BITOR");
        case MULT:            return("MULT");
        case DIV:             return("DIV");
        case MOD:             return("MOD");
        case BITAND:          return("BITAND");
        case AND:             return("AND");
        case OR:              return("OR");
        case SMCLN:           return("SMCLN");
        case EOF:             return("EOF");
        case LITERAL:         return("LITERAL");
        case ENDFRAGMENT:     return("ENDFRAGMENT");
        case IF:              return("IF");
        case ELSE:            return("ELSE");
        case WHILE:           return("WHILE");
        case WRITE:           return("WRITE");
        case READ:            return("READ");
    }
}

/*
 * Retorna os caracteres correspondentes ao valor numerico do token
 */
char *retornaLiteralToken(int token) {
    switch(token) {
        case FLOAT:           return("FLOAT");
        case INTEGER:         return("INTEGER");
        case PARAM:           return("PARAM");
        case VECTOR:          return("VECTOR");
        case NUM:             return("NUM");
        case ID:              return("ID");
        case FRAGMENT:        return("FRAGMENT");
        case OPENBRA:         return("[");
        case CLOSEBRA:        return("]");
        case COMMA:           return(",");
        case ASSIGN:          return("=");
        case OPENPAR:         return("(");
        case CLOSEPAR:        return(")");
        case NOT:             return("!");
        case PLUS:            return("+");
        case MINUS:           return("-");
        case EQUALS:          return("==");
        case LT:              return("<");
        case LE:              return("<=");
        case GE:              return(">=");
        case GT:              return(">");
        case NE:              return("!=");
        case BITOR:           return("|");
        case MULT:            return("*");
        case DIV:             return("\\");
        case MOD:             return("%");
        case BITAND:          return("&");
        case AND:             return("&&");
        case OR:              return("||");
        case SMCLN:           return(";");
        case EOF:             return("EOF");
        case LITERAL:         return("LITERAL");
        case ENDFRAGMENT:     return("ENDFRAGMENT");
        case IF:              return("IF");
        case ELSE:            return("ELSE");
        case WHILE:           return("WHILE");
        case WRITE:           return("WRITE");
        case READ:            return("READ");
    }
}
 
 /* Inicializa o analizador Lexico */
void inicializaAnalisadorLexico(char *arquivo) {
    inicializaBuffer(arquivo);
    inicializaTabSimbolos();
}

/* Finaliza o analisador Lexico */
void finalizaAnalisadorLexico() {
    finalizaTabSimbolos();
    finalizaBuffer();
}

int retornaLinha(){
    return linha;
};
