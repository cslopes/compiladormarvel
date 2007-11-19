/**
*
*           MARVEL COMPILER
*/
#include <stdio.h>
#include <iostream>
#include "DeclaracaoClassesArvore.h"

using namespace std;

void inicializaAnalisadorLexico(char *);
void imprimirASAbstrata(ProgramNode* prgmNode);
ProgramNode* analiseSintatica();
void imprimeTabSimbolos();
void finalizaAnalisadorLexico();

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

   imprimirASAbstrata(analiseSintatica());

   imprimeTabSimbolos();
 
   finalizaAnalisadorLexico();

   system("PAUSE");
   
   return 0;
}
