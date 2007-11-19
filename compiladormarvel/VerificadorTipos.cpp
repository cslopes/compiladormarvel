#include "VerificadorTipos.h"
#include "ClassesArvoreAbstrata.h"
#include "Erro.h"
#include "Tokens.h"
#include "TabSimbolos.h"

/* ----------------------------------------------------------------------------
  Implementa��o do construtor e dos m�todos visitantes da
  classe respons�vel por verificar o tipo da vari�vel.
  
  Nos casos em que o objeto Node passado para o m�todo visitante tem
  mais de um construtor, os atributos devem ser testados antes do m�todo
  accept(visitor) ser chamado.
-----------------------------------------------------------------------------*/

 
// Implementa o construtor da classe de verificacao
VerificadorTipos::VerificadorTipos() {
     tipo = EMPTY;
     linha = 0;
}
/*---------------------------------------------------------------------------*/
// Implementa os m�todos visitantes
/*---------------------------------------------------------------------------*/

void VerificadorTipos::visit(AddOpNode* additionalOpNode){
     // Chama o visitante para recuperar o tipo do lado direito
     (additionalOpNode->expressionNode1->accept(this));
     int tipoExpressionNode1 = tipo;
     
     // Chama o visitante para recuperar o tipo do lado esquerdo
     (additionalOpNode->expressionNode2->accept(this));
     int tipoExpressionNode2 = tipo;
     
     // Verifica se os tipos sao iguais
     if (tipoExpressionNode1 != tipoExpressionNode2) {
        // Lanca erro semantico de diferenca de tipos na operacao adicao
        emiteErroSemantico(ERRO_INCOMPATIBILIDADE_TIPO, "ADICAO", linha);
     }
     
     // Verifica se os tipos sao iguais a tipos nao compativeis com a operacao
     if ((tipoExpressionNode1 != INTEGER) || (tipoExpressionNode1 != FLOAT) ||
         (tipoExpressionNode2 != INTEGER) || (tipoExpressionNode2 != FLOAT)) {
        // Lan�a ERRO de tipo incompativel com a operacao de adicao
         emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "ADICAO", linha);                          
     }
          
     // Atribui o tipo do lado esquerdo ao tipo global para continuar o Semantico
     tipo = tipoExpressionNode2;
}

void VerificadorTipos::visit(ArrayNode* arrayNode){
     // Chama o visitante para recuperar o tipo do vetor
     (arrayNode->idNode->accept(this));
     int tipoArray = tipo;
     
     // Chama o visitante para recuperar o tipo da expressao
     (arrayNode->expressionNode->accept(this));
     int tipoExpressionNode = tipo;
     
     if (tipoExpressionNode != INTEGER) {
        // Lan�a erro de tipo incompat�vel para referencia de ind�ce do vetor                       
        emiteErroSemantico(ERRO_TIPO_INCOMPATIVEL_INDICE_ARRAY, NULL, linha);
     }
     
     // Estabelecer uma forma de verificar se o valor passado pertence ao inter-
     // valo que define os elementos do array.
     
     tipo = tipoArray;    
     
}

void VerificadorTipos::visit(AssignNode* assignNode){
     // Chama o visitante para recuperar o tipo do id que recebera a atribui��o
     (assignNode->idNode)->accept(this);
     int tipoId = tipo;
     
     // Chama o visitante para recuperar o tipo da primeira express�o
     (assignNode->expressionNode1->accept(this));
     int tipoExpressionNode1 = tipo;
     
     // Chama o visitante para recuperar o tipo da segunda express�o
     (assignNode->expressionNode2->accept(this));
     int tipoExpressionNode2 = tipo;
     
     if ((tipoExpressionNode1 != tipoId) || (tipoExpressionNode2 != tipoId)){
        // Lan�a erro de tipos incompat�veis durante uma atribui��o
        emiteErroSemantico(ERRO_TIPO_INCOMPATIVEL_ATRIBUICAO, NULL, linha);
     }
     
     if (tipoExpressionNode1 != tipoExpressionNode2){
        // Lan�a erro de tipos incompat�veis 
        emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, NULL, linha);
     }
     
     // O n� tem que retornar o tipo do ID para n�vel superior na �rvore.
     tipo = tipoId;
}

void VerificadorTipos::visit(BitwiseOpNode* bitwiseOpNode){
     // Chamao visitante para recuperar o tipo do lado direito
     (bitwiseOpNode->expressionNode1->accept(this));
     int tipoExpressionNode1 = tipo;
     
     // Chama o visitante para recuperar o tipo do lado esquerdo
     (bitwiseOpNode->expressionNode2->accept(this));
     int tipoExpressionNode2 = tipo;
     
     // Verifica se os tipos sao iguais
     if (tipoExpressionNode1 != tipoExpressionNode2) {
        // Lanca erro semantico de diferenca de tipos entre os operandos
        emiteErroSemantico(ERRO_INCOMPATIBILIDADE_TIPO, "BITWISEOPNODE", linha);
     }
     
     // Verifica se os tipos sao compativeis para essa operacao
     if (tipoExpressionNode1 != BOOLEAN || tipoExpressionNode2 != BOOLEAN) {
        // Lanca erro semantico de incompatibilidade de tipos na operacao booleana
        emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "BITWISE", linha);
     }
     
     // Atribui o tipo do lado esquerdo ao tipo global para continuar o Semantico
     tipo = BOOLEAN;
}

void VerificadorTipos::visit(BoolOpNode* boolOpNode){
     // Chama o visitante para recuperar o tipo do lado direito
     (boolOpNode->expressionNode1->accept(this));
     int tipoExpressionNode1 = tipo;
     
     // Chama o visitante para recuperar o tipo do lado esquerdo
     (boolOpNode->expressionNode2->accept(this));
     int tipoExpressionNode2 = tipo;
     
     // Verifica se os tipos sao iguais
     if (tipoExpressionNode1 != tipoExpressionNode2) {
        // Lanca erro semantico de diferenca de tipos na operacao booleana
        emiteErroSemantico(ERRO_INCOMPATIBILIDADE_TIPO, "BOOLEANA", linha);
     }
     
     // Verifica se os tipos sao compativeis para essa operacao
     if (tipoExpressionNode1 != BOOLEAN || tipoExpressionNode2 != BOOLEAN) {
        // Lanca erro semantico de incompatibilidade de tipos na operacao booleana
        emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "BOOLEANA", linha);
     }
     
     // Atribui o tipo do lado esquerdo ao tipo global para continuar o Semantico
     tipo = BOOLEAN;
}

void VerificadorTipos::visit(CallNode* callNode){
}

void VerificadorTipos::visit(ConstantNode* constantNode){
     (constantNode->accept(this));
     int tipoConstantNode = tipo;
     
     if (tipoConstantNode == NUM) {
        // O n� � do tipo NUM
        tipo = INTEGER;
     } else {
        // Sen�o o n� � do tipo LITERAL, que no caso � interpretado como CHAR.
        tipo = CHAR;
     }
}

void VerificadorTipos::visit(ExpressionListNode* expressionListNode){
     (expressionListNode->expressionNode->accept(this));
     if (expressionListNode->expressionListNode)
        (expressionListNode->expressionListNode->accept(this));
}

void VerificadorTipos::visit(FragCallNode* fragCallNode){
     // Chama o visitante do FragCallNode para recuperar o tipo do id
     (fragCallNode->idNode->accept(this));
     int tipoId = tipo;
     
     // Chama o visitante do FragCallNode para recuperar o tipo da express�o
     (fragCallNode->expressionList->accept(this));
     int tipoExpressionNode = tipo;
     
     // Verifica a compatibilidade de tipos entre os integrantes do n� FragCall
     if (tipoExpressionNode != tipoId){
        // Lan�a erro de incompatilidade de tipo na chamada do fragmento
        emiteErroSemantico(ERRO_TIPO_INCOMPATIVEL_CHAMADA_FRAG, NULL, linha);  
     }
     
     // O n� deve retornar o tipo do ID
     tipo = tipoId;
}

void VerificadorTipos::visit(FragmentNode* fragmentNode){
     (fragmentNode->statementListNode->accept(this));

     // Esse n� n�o retorna tipo
     tipo = EMPTY;
}

void VerificadorTipos::visit(IdListNode* idListNode){
     // Chama o visitante para a lista de n�s
     if (idListNode->idListNode) (idListNode->idListNode->accept(this));
     
     // Chama o visitante para o idNode filho
     (idListNode->idNode->accept(this));
     
     // O n� idNode filho recupera o tipo atual
}

void VerificadorTipos::visit(IdNode* idNode){
//     fprintf(stdout, "---------------------------------------------------\n");
//     fprintf(stdout, "variavel: %s\n", retornaCharToken(idNode->registro->indiceLexema));     
//     fprintf(stdout, "tipo do no: %d\n", idNode->registro->tipo);
//     fprintf(stdout, "numero da linha: %d\n", idNode->registro->linha);     
     tipo = idNode->registro->tipo;
     linha = idNode->registro->linha;
}

void VerificadorTipos::visit(IfNode* ifNode){
     // Chama o visitante para recuperar o tipo da express�o
     (ifNode->expressionNode->accept(this));
     int tipoExpressionNode = tipo;
     
     if (tipoExpressionNode != BOOLEAN) {
        // Lan�a erro de expressao n�o booleana numa clausula if
        emiteErroSemantico(ERRO_EXPRESSAO_NAO_BOOLEANA, NULL, linha);
     }
     
     // Visita a cl�usula ENTAO
     (ifNode->statementNode1->accept(this));
     
     // Verifica se a cl�usula SENAO est� vazia e chama seu visitante
     if (ifNode->statementNode2) (ifNode->statementNode2->accept(this));
     
     // O tipo desse n� � vazio pois n�o retorna ao n�vel superior
     tipo = EMPTY;                          
}

void VerificadorTipos::visit(LiteralNode* literalNode){
     tipo = CHAR;
     //linha = literalNode->registro->linha;
}

void VerificadorTipos::visit(ModifierListNode* modifierListNode){
     
     // Verifica se o modifierList desse n� est� vazio e chama seu visitante
     if (modifierListNode->modifierListNode) (modifierListNode->modifierListNode->accept(this));
     
     // Chama o visitante do modifier desse n�
     (modifierListNode->modifierNode->accept(this));
     
     // Invocando o accept do modifierNode, a vari�vel tipo fica setada para esse n�.
}

void VerificadorTipos::visit(ModifierNode* modifierNode){
     // Atribui ao tipo, o definido no n� modifier pelo atributo int modifier
     tipo = modifierNode->modifier;
}   

void VerificadorTipos::visit(MultOpNode* multOpNode){
     // Chama o visitante para recuperar o tipo do lado direito
     (multOpNode->expressionNode1->accept(this));
     int tipoExpressionNode1 = tipo;
     
     // Chama o visitante para recuperar o tipo do lado esquerdo
     (multOpNode->expressionNode2->accept(this));
     int tipoExpressionNode2 = tipo;
     
     // Verifica se os tipos sao iguais
     if (tipoExpressionNode1 != tipoExpressionNode2) {
        // Lanca erro semantico de diferenca de tipos na operacao multiplicacao
        emiteErroSemantico(ERRO_INCOMPATIBILIDADE_TIPO, "MULTIPLICACAO", linha);
     }
     
     // Verifica se os tipos sao compativeis para essa operacao
     if ((tipoExpressionNode1 != INTEGER) || 
         (tipoExpressionNode1 != FLOAT) ||
         (tipoExpressionNode2 != INTEGER) ||
         (tipoExpressionNode2 != FLOAT)) {
        // Lanca erro semantico de incompatibilidade de tipos na operacao multiplicacao
        emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "MULTIPLICACAO", linha);
     }
     
     // Atribui o tipo do lado esquerdo ao tipo global para continuar o Semantico
     tipo = tipoExpressionNode2;
}

void VerificadorTipos::visit(NameDeclNode* nameDeclNode){
     // Chama o visitante para a lista de Modifiers
     (nameDeclNode->modifierListNode->accept(this));
     
     // Chama o visitante para a lista de ids
     (nameDeclNode->idListNode->accept(this));
     
     // Esse n� n�o retorna tipo para o n�vel acima na ASA
     tipo = EMPTY;
}

void VerificadorTipos::visit(NegativeNode* negativeNode){
     // Chama o visitante para recuperar o tipo da expressao
     (negativeNode->expressionNode->accept(this));
     
     // Recupera o tipo da expressao
     int tipoExpressionNode = tipo;
     
     // Verifica se a expressao retorna um tipo valido para negacao
     if ((tipoExpressionNode != INTEGER) || 
         (tipoExpressionNode != FLOAT) ||
         (tipoExpressionNode != NUM)){
         // Lanca erro de tipo incompativel com operador negativo
         emiteErroSemantico(ERRO_INCOMPATIBILIDADE_TIPO, "NEGACAO", linha);
     }
     
     // Seta o tipo para o no atual
     tipo = tipoExpressionNode;
}

void VerificadorTipos::visit(NotNode* notNode){
     (notNode->expressionNode->accept(this));
     int tipoNotNode = tipo;
     if (tipoNotNode != BOOLEAN) {
        // Lanca erro de tipo incompativel na comparacao not equal
        emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "NEGACAO", linha);
     }
     tipo = BOOLEAN;
}

void VerificadorTipos::visit(NumberNode* numberNode){
     tipo = numberNode->registro->tipo;
     linha = numberNode->registro->linha;
}

void VerificadorTipos::visit(ProgramNode* programNode){
     // Chama o visitante para seu StatementList
     (programNode->stmtListNode->accept(this));
     
     // Esse n� n�o retorna tipo
     tipo = EMPTY;
}

void VerificadorTipos::visit(ReadNode* readNode){
     // Vari�veis auxiliares do m�todos
     int tipoExpressao;

     if (readNode->expressionListNode){
          ExpressionListNode *expressionListNode = readNode->expressionListNode;
          if (expressionListNode == NULL){
             // Lan�ar erro sem�ntico com ReadNode sem express�o definida
          } else {
                 while (expressionListNode != NULL){
                       // Chama o visitante para recuperar o tipo da express�o desse n�-filho
                       (expressionListNode->expressionNode->accept(this));
                       tipoExpressao = tipo;
                       
                       if ((tipoExpressao != INTEGER) || (tipoExpressao != FLOAT)){
                          // Lan�ar erro semantico de tipo incompativel com a operacao
                          emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "LEITURA", linha);
                       }
                       
                       // Recupera a lista filha de express�es
                       expressionListNode = expressionListNode->expressionListNode;
                       
                 }// end while
          } // end if 
     } // end if 

     // Chama o visitante para o array filho e faz sua verifica��o
     if (readNode->arrayNode) (readNode->arrayNode->accept(this));
     
     // N�o chama o visitante para o id filho, pois isso seria necess�rio no 
     // caso de verificar o seu tipo, sendo que o visitante do id filho 
     // s� recupera o seu tipo.

     // O n� atual n�o retorna tipo 
     tipo = EMPTY;
}

void VerificadorTipos::visit(RelOpNode* relOpNode){
     // Chama o visitante para recuperar o tipo do lado direito
     (relOpNode->expressionNode1->accept(this));
     int tipoExpressionNode1 = tipo;
     
     // Chama o visitante para recuperar o tipo do lado esquerdo
     (relOpNode->expressionNode2->accept(this));
     int tipoExpressionNode2 = tipo;
     
     // Verifica se os tipos sao iguais
     if (tipoExpressionNode1 != tipoExpressionNode2) {
        // Lanca erro semantico de incompatibilidade de tipos na operacao relacional
        emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "RELACIONAL", linha);
        
     } // Verifica com o else else {
          // tipo = BOOLEAN;
          //}
     
     // Atribui o tipo do lado esquerdo ao tipo global para continuar o Semantico
     tipo = BOOLEAN;
}

void VerificadorTipos::visit(StatementListNode* stmtListNode){
     (stmtListNode->statementNode->accept(this));
     if (stmtListNode->statementListNode)
        (stmtListNode->statementListNode->accept(this));
}

void VerificadorTipos::visit(WhileNode* whileNode){
     // Chama o visitante para recuperar o tipo da express�o
     (whileNode->expressionNode->accept(this));
     int tipoExpressionNode = tipo;
     
     if (tipoExpressionNode != BOOLEAN) {
        // Lan�a erro de express�o n�o booleana em condicional while
        emiteErroSemantico(ERRO_EXPRESSAO_NAO_BOOLEANA, NULL, linha);
     }
     
     // Chama o vistante para o conte�do do while.
     (whileNode->statementNode->accept(this));
     
     // O tipo desse n� � vazio pois n�o retorna ao n�vel superior     
     tipo = EMPTY;
}

void VerificadorTipos::visit(WriteNode* writeNode){
     // Vari�veis locais auxiliares
     //----------------------------------------------------------------
     
     // Recupera a lista de expressao do n� Write
     ExpressionListNode* expressionList = writeNode->expressionListNode;
     // Declara um inteiro que deve conter o tipo de cada express�o
     int tipoExpression;

     // Verifica se a lista de express�es do n� Write est� vazia.
     if (expressionList == NULL){
         // Lan�a erro de comando write sem express�o
         emiteErroSemantico(ERRO_COMANDO_SEM_EXPRESSAO, "WRITE", linha);
         
     } else {
            // Efetua uma itera��o entre os elementos expressions da lista
            while (expressionList != NULL){
                  // Chama o visitante para recuperar o tipo da express�o
                  (expressionList->expressionNode->accept(this));
                  tipoExpression = tipo;
                  // Verifica se o tipo da express�o atual � compat�vel 
                  if ((tipoExpression != INTEGER) &&
                      (tipoExpression != FLOAT)   &&
                      (tipoExpression != CHAR)){
                      // Lan�a erro de tipo incompat�vel com o comando 
                      emiteErroSemantico(ERRO_TIPO_NAO_ESPERADO_OPERACAO, "WRITE", linha);
                  }
                  // Recupera a pr�xima lista
                  expressionList = expressionList->expressionListNode;
            }
     }
     // O n� Write n�o precisa enviar tipo a n�vel superior.
     tipo = EMPTY;
}

