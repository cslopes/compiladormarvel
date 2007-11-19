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
   
   ProgramNode *ASA = analiseSintatica();

   imprimirASAbstrata(ASA);
       
       VerificadorEscopo* verif = new VerificadorEscopo();
       ASA->accept(verif);

   imprimeTabSimbolos();
 
   finalizaAnalisadorLexico();

     system("PAUSE");
   
   return 0;
}
