#include <stdio.h>

/* Defini��o de c�digos de erros l�xicos */
#define ERRO_GETTOKEN                         9000
#define ERRO_NUM_DECIMAL                      9001
#define ERRO_NUM_REAL                         9002
#define ERRO_EOF_LITERAL                      9003
#define ERRO_EOF_COMENTARIO                   9004
#define ERRO_MEMORIA_INSUF                    9005
#define ERRO_PARAM_INVALIDO                   9006
#define ERRO_ABRIR_ARQUIVO                    9007

/* Defini��o de c�digos de erros sint�ticos */
#define ERRO_TOKEN_ESPERADO                   8000
#define ERRO_TOKEN_INVALIDO                   8001
#define ERRO_EOF                              8002

/* Defini��o de c�digos de erros sem�nticos */
#define ERRO_TIPO_NAO_ESPERADO_OPERACAO       7000
#define ERRO_INCOMPATIBILIDADE_TIPO           7001
#define ERRO_TIPO_INCOMPATIVEL_INDICE_ARRAY   7002
#define ERRO_TIPO_INCOMPATIVEL_ATRIBUICAO     7003
#define ERRO_EXPRESSAO_NAO_BOOLEANA           7004
#define ERRO_COMANDO_SEM_EXPRESSAO            7005
#define ERRO_TIPO_INCOMPATIVEL_CHAMADA_FRAG   7006

// nvia uma mensagem de erro para stderr referente ao erro sint�tico
void emiteErroLexico(int, int);

// Envia uma mensagem de erro para stderr referente ao erro sint�tico
void emiteErroSintatico(int, int, int);

// Envia uma mensagem de erro para stderr referente ao erro semantico
void emiteErroSemantico(int, char*, int);


