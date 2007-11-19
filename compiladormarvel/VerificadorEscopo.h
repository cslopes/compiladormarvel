/*
*/


#ifndef VERIFICADORESCOPO_H
#define VERIFICADORESCOPO_H

#include "Visitor.h"
#include "TabSimbolos.h"

// Define os atributos e m�todos visitantes.
class VerificadorEscopo : public Visitor {
          public:
             // Declara��o do construtor
             VerificadorEscopo();
             
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
              

              void iniciaEscopo();
              void terminaEscopo();
              void insereEscopo(REGISTRO *entrada);
              int retornaEscopo(int nivel);
                                       
};
#endif
