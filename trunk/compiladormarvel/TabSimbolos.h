#ifndef _TabSimbolos_h_included_
#define _TabSimbolos_h_included_

#define HASHPRIME           221   /*  tamanho inicial da tabela de simbolos */
#define LEXINI              1024  /*  tamanho inicial do array de lexemas  */


typedef struct Registro {
    int              indiceLexema;    // Indice do lexema no array de lexemas
    int              token;           // Token do registro
    int              escopo;           // Escopo do registro
    int              ativo;           // Registro ativo ou n�o
    struct Registro  *prox;           // Proximo registro
    int              tipo;
} REGISTRO;


typedef struct Array_Lexemas {
    char  *caracteres;                // Lexema
    int   proxIndice;                 // Proximo indice do array
    int   tamanho;                    // Tamanho atual do array
} ARRAY_LEXEMAS;

// Inicializa a Tabela de Simbolos
void inicializaTabSimbolos();

// Finaliza a Tabela de Simbolos
void finalizaTabSimbolos();

//Imprime a tabela de Simbolos
void imprimeTabSimbolos();

// Insere o token e respectivo lexema na tabela de s�mbolos
int insereTabSimbolos(int, char*);

// Verifica se j� existe o registro para o lexema na tabela de s�mbolos. Caso
// exista, retorna o mesmo, sen�o retorna 0.
REGISTRO *buscaTabSimbolos(char*);

// Retorna o indice do lexema buscado
int retornaIndiceLexemaAtual();

// Retorna o registro atual
REGISTRO *retornaRegistroAtual();

// Retorna o char correspondente a posi�ao pos
char* retornaCharToken(int pos);

#endif
