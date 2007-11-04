
/**
 * 
 *          Analisador Sint�tico
 * 
 */
#include "ClassesArvoreAbstrata.h"

// Fun��o que casa o token lido com o esperado
void match(int token, int follow[], int* iLexema);

// Retorna se o lookahead pertence ao follow
int lookaheadPertenceFollow(int follow[]);

//Imprime a Arvore de Sintaxe Abstrata
void imprimirASAbstrata(ProgramNode* prgmNode);

/*Inicia a analise sintatica*/
ProgramNode* analiseSintatica();


//Produ��o Program
ProgramNode* program();

//Produ��o StatementList
StatementListNode* statementList();

//Produ��o StatementList'
StatementListNode* statementListLinha(StatementNode* stmLinha);

//Produ��o Statement
StatementNode* statement();

//Produ��o Statement'
StatementNode* statementLinha();

// Produ��o StatementDuasLinhas
StatementNode* statementDuasLinhas(IdNode *idDuasLinhas);

//Produ��o NameDecl
NameDeclNode* namedecl();

//Produ��o Fragment
StatementNode* fragment();

//Produ��o Expression
ExpressionNode* expression();

//Produ��o Expression'
ExpressionNode* expressionLinha(ExpressionNode* sexprE);

//Produ��o Expression''
ExpressionNode* expressionDuasLinhas(ExpressionNode* cmpExprE);

//Produ��o BoolExp
ExpressionNode* boolExp(ExpressionNode* boolExprE);

//Produ��o Bool_Or
ExpressionNode* boolOr(ExpressionNode* orExprE);

//Produ��o Bool_and
ExpressionNode* boolAnd(ExpressionNode* andExprE);

//Produ��o Expr_List
ExpressionListNode* expressionList();


//Produ��o Expr_List'
ExpressionListNode* expressionListLinha();

//Produ��o ModifierList
ModifierListNode* modifierList();

//Produ��o ModifierList'
ModifierListNode* modifierListLinha(ModifierNode* modV);

//Produ��o Id_List
IdListNode* idList();

//Produ��o Id_List'
IdListNode* idListLinha();

//Produ��o Simple_Exp
ExpressionNode* simpleExpression();

//Produ��o Simple_Exp'
ExpressionNode* simpleExpressionLinha(ExpressionNode* addExpE);

//Produ��o Comp_Op
int compOp();

//Produ��o Comp_Op
int relOp();

//Produ��o Modifier
ModifierNode* modifier();

//Produ��o Term
ExpressionNode* term();

//Produ��o Term'
ExpressionNode* termLinha(ExpressionNode* multExpE);

//Produ��o Sign
int signOp();

//Produ��o Add_Op
int addOp();

//Produ��o Mult_Op
int multOp();

//Produ��o Factor
ExpressionNode* factor();

//Produ��o Factor'
ExpressionNode* factorLinha(IdNode* idN);

// Retorna se o lookahead pertence ao first do n�o terminal
int lookaheadPertenceFirst(int naoTerminal);
