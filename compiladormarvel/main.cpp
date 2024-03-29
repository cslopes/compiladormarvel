/**
*
*           MARVEL COMPILER
*/

#include <cstdlib>
#include <iostream>
#include "Buffer.h"
#include "TabSimbolos.h"
#include "AnalLex.h"
#include "AnalSint.h"
#include "VerificadorEscopo.h"
#include "VerificadorTipos.h"
#include "Tradutor.h"
#include "VisitorArvoreIntermediaria.h"


using namespace std;

int main(int argc, char *argv[])
{
   printf("\t\t     --- MARVEL COMPILER ---\n\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                                   ~\n");
   printf("                  �         ��        \n");
   printf("                          ��        \n");
   printf("    �          ��        ���   \n");
   printf("    ��              ��    �     ���   \n");
   printf("    ��              ��    �    ���   \n");
   printf("     �             ��         ���       \n");
   printf("     ���                         ��        \n");
   printf("                          ��          ��        \n");
   printf("        ��        ��            ��    ��        \n");
   printf("                  ���     � ���   \n");
   printf("                       �   � ���   \n");
   printf("                �   ����     ���   \n");
   printf("                �   �        ���       ��\n");
   printf("                      �   ��           �\n");
   printf("                      ���           ����\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n\n\t\t     -----------------------\n\n");

   inicializaAnalisadorLexico(argv[1]);
   imprimeTabSimbolos();

   ProgramNode *ASA = analiseSintatica();
   imprimirASAbstrata(ASA);
       
       // Inicia a verifica��o de escopo e declara��o de vari�veis
       VerificadorEscopo* verifEscopo = new VerificadorEscopo();
       ASA->accept(verifEscopo);
       imprimirASAbstrata(ASA);
          
       // Inicia a verifica��o de tipos
       VerificadorTipos* verifTipos = new VerificadorTipos();
       ASA->accept(verifTipos);
       
       Tradutor* tradutor = new Tradutor();
       ASA->accept(tradutor);
       
       
   finalizaAnalisadorLexico();

     system("PAUSE");
   
   return 0;
}
