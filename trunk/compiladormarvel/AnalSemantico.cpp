#include "AnalSemantico.h"
#include "VerificadorEscopo.h"
#include "VerificadorVariaveis.h"
#include "VerificadorTipos.h"



/*

  Arquivo de implementa��o do header AnalSemantico, respons�vel 
  por iniciar e finalizar a an�lise sem�ntica, tendo suporte do
  padr�o Visitor para cada um dos m�dulos verificadores de regras
  sem�nticas.

*/

void iniciarAnaliseSemantica(ProgramNode* programNode){
     
     // Verifica se o par�metro passado n�o � nulo
     if (programNode != NULL) {
        // Inicia a an�lise sem�ntica chamando cada uma das classes que implementam regras sem�nticas
        
        // Verifica��o de escopo
        VerificadorEscopo* verificadorEscopo = new VerificadorEscopo();
        (programNode->accept(verificadorEscopo));
        
        // Verifica��o de tipos
        VerificadorTipos* verificadorTipos = new VerificadorTipos();
        (programNode->accept(verificadorTipos));
        
        // Verifica��o de vari�veis
        VerificadorVariaveis* verificadorVariaveis = new VerificadorVariaveis();
        (programNode->accept(verificadorVariaveis));
     }
                          
}

void finalizarAnaliseSemantica(){
     
}
