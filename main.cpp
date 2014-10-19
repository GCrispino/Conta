#include <iostream>
#include <conio.h>
#include "Conta.h"

using namespace std;

int main(int argc, char **argv)
{
	Conta c("Joao",23456,"444556");
	
	c.registraOperacao(0,500);
	getch();
	c.imprimeHistorico();
	
	return 0;
}
