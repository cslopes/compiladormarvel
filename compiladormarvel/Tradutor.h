
#ifndef _Tradutor_h
#define _Tradutor_h

#include "Visitor.h"
#include "TabSimbolos.h"
#include "ArvoreIntermediaria.h"
#include "CodigoIntermediario.h"



// Define os atributos e m�todos visitantes.
class Tradutor : public Visitor {
      	
       private:

		ListaDeFragmentos * Fragmentos;
		ListaAcesso* dados;
		StmList * corpo;
		Exp * expressao;
		Stm * sentenca;
        int numero_temporario;
        int numero_rotulo;
        int numero_literal;

		
      public:
            // Declara��o do construtor
             Tradutor();
                          
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

              ListaDeFragmentos* getFragmentos();
              void adicionaFragmento(Fragmento * frag);
              void adicionaSentenca(Stm * sentenca);
  
             
                                       
};
#endif
