/*
                        AnalisadorLexico
                        
  Description: M�dulo referente a implementa��o do aut�mato que especifica o 
  analisador l�xico do compilador Marvel. Sua principal fun��o � proximoToken()
  que verifica a partir da string de entrada, enviada pelo BufferEntrada, os 
  caracteres a formarem um pr�ximo token. Ao encontrar uma string referente 
  a um token, retorna o valor inteiro respectivo - os valores inteiros dos 
  tokens est�o definidos em tokens.h.
*/

/* Defini��o de valores */
#define SPACE           ' '
#define TAB             '\t'
#define LINE            '\n'
#define RETURN          '\r'

/* Inicializa o analizador Lexico */
void inicializaAnalisadorLexico(char *);

/* Finaliza o analisador Lexico */
void finalizaAnalisadorLexico();

/* Fun��o de reconhecimento de token */
/* A fun��o retorna um inteiro referente a um token especificado em tokens.h */
int proxToken();

/*Fun��o que imprime o token*/
void emitirToken(int, char*);

/*Retorna os caracteres correspondentes ao valor numerico do token */
char *retornaToken(int);

/*
 * Retorna os caracteres correspondentes ao valor numerico do token
 */
char *retornaLiteralToken(int token);

int retornaLinha();
