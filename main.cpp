#include <iostream>
#include <conio.h>
#include "Conta.h"

using namespace std;

int main(int argc, char **argv)
{
	Conta c("Joao",23456,"444556");
	
	c.registraOperacao(0,500);
	c.registraOperacao(1,200);
	
	c.imprimeHistorico();
	
	//Conta c1(c);
	Conta c1 = c;
	
	c1.registraOperacao(0,300);
	
	c1.imprimeHistorico();
	
	return 0;
}
