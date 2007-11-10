#include "VerificadorTipos.h"

/* ----------------------------------------------------------------------------
  Implementa��o do construtor e dos m�todos visitantes da
  classe respons�vel por verificar o tipo da vari�vel.
  
  Nos casos em que o objeto Node passado para o m�todo visitante tem
  mais de um construtor, os atributos devem ser testados antes do m�todo
  accept(visitor) ser chamado.
  
-----------------------------------------------------------------------------*/

 
// Implementa o construtor da classe de verificacao
VerificadorTipos::VerificadorTipos() {}
/*---------------------------------------------------------------------------*/


// Implementa os m�todos visitantes
/*---------------------------------------------------------------------------*/

void VerificadorTipos::visit(AddOpNode* additionalOpNode){
}

void VerificadorTipos::visit(ArrayNode* arrayNode){
}

void VerificadorTipos::visit(AssignNode* assignNode){
     (assignNode->idNode)->accept(this);
      
}

void VerificadorTipos::visit(BitwiseOpNode* bitwiseOpNode){
}

void VerificadorTipos::visit(BoolOpNode* boolOpNode){
}

void VerificadorTipos::visit(CallNode* callNode){
}

void VerificadorTipos::visit(ConstantNode* constantNode){
}

void VerificadorTipos::visit(ExpressionListNode* expressionListNode){
}

void VerificadorTipos::visit(FragCallNode* fragCallNode){
}

void VerificadorTipos::visit(FragmentNode* fragmentNode){
}

void VerificadorTipos::visit(IdListNode* idListNode){
}

void VerificadorTipos::visit(IdNode* idNode){
}

void VerificadorTipos::visit(IfNode* ifNode){
}

void VerificadorTipos::visit(LiteralNode* literalNode){
}

void VerificadorTipos::visit(ModifierListNode* modifierListNode){
}

void VerificadorTipos::visit(ModifierNode* modifierNode){
}   

void VerificadorTipos::visit(MultOpNode* multOpNode){
}

void VerificadorTipos::visit(NameDeclNode* nameDeclNode){
}

void VerificadorTipos::visit(NegativeNode* negativeNode){
}

void VerificadorTipos::visit(NotNode* notNode){
}

void VerificadorTipos::visit(NumberNode* numberNode){
}

void VerificadorTipos::visit(ProgramNode* programNode){
}

void VerificadorTipos::visit(ReadNode* readNode){
}

void VerificadorTipos::visit(RelOpNode* relOpNode){
}

void VerificadorTipos::visit(StatementListNode* stmtListNode){
}

void VerificadorTipos::visit(WhileNode* whileNode){
}

void VerificadorTipos::visit(WriteNode* writeNode){
}

