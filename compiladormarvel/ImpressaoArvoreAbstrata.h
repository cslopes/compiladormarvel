/*
  Arquivo header que define a classe ImpressaoArvoreAbstrata, que herda de
  Visitor (� a implementa��o de Visitor).
*/
#ifndef _ImpressaoArvoreAbstrata_h_included_
#define _ImpressaoArvoreAbstrata_h_included_

#include "Visitor.h"

// Define os atributos e m�todos visitantes.
class ImpressaoArvoreAbstrata : public Visitor {
      private:
             // Define o n�vel atual da �rvore
             int nivel;
      public:
             // Declara��o do construtor
             ImpressaoArvoreAbstrata();
             
             // M�todos visitantes
              void visit(ProgramNode* programNode);
              void visit(StatementListNode* stmtNode);
              void visit(NameDeclNode* nameDeclNode);
              void visit(FragmentNode* fragmentNode);
              void visit(IfNode* ifNode);
              void visit(WhileNode* whileNode);
              void visit(AssignNode* assignNode);
              void visit(FragCallNode* fragCallNode);
              void visit(ReadNode* readNode);
              void visit(WriteNode* writeNode);
              void visit(ConstantNode* constantNode);
              void visit(ExpressionListNode* expressionListNode);
              void visit(CallNode* callNode);
              void visit(ArrayNode* arrayNode);
              void visit(RelOpNode* relationalOpNode);
              void visit(AddOpNode* additionalOpNode);
              void visit(MultOpNode* multOpNode);
              void visit(BoolOpNode* boolOpNode);
              void visit(BitwiseOpNode* bitwiseOpNode);
              void visit(NotNode* notNode);
              void visit(NegativeNode* negativeNode);
              void visit(ModifierListNode* modifierListNode);
              void visit(ModifierNode* modifierNode);
              void visit(IdNode* idNode);
              void visit(IdListNode* idListNode);
              void visit(NumberNode* numberNode);
              void visit(LiteralNode* literalNode);
             
              // M�todo respons�vel pela impress�o do n�vel da �rvore
              void imprimeNivel();
                                       
};
#endif
