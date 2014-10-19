/*
    Operator =
    Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada
    Usar o destrutor
    X Construtor de cópia
    Operator << friend
    X Um const static 

 * A classe "conta" tem como objetivo guardar atributos e operaçãoes referentes a uma conta de um banco.
 * A sua estrutura é composta por dados comuns de uma conta de banco, e realiza operações de saldo e pagamento, dentre outras.
 * Parte de sua implementação será aproveitada pelo o que ja foi feito na classe "Caixa_Eletronico", onde apesar de não haver
 * uma classe "conta", algumas de suas operações ja estão definidas, podendo ser reaproveitadas.
*/


#include <iostream>

using namespace std;

#ifndef CONTA_H
#define CONTA_H

class Conta
{
	
private:
	string nome; //Nome do usuario da conta.
	int numero;  //Número da conta.
	string senha;   //Senha da conta
	float saldo; //Saldo da conta
	//const static int qtdmax; //Quantidade maxima de contas que podem ser registradas.
	float *historico[2]; //indica atraves de um vetor de ponteiros as ultimas operações feitas e quanto dinheiro foi movimentado...
						//...onde a posição zero indica o dinheiro movimentado nos últimos saques...
						//...e a posição 1 indica o dinheiro movimentado nos últimos pagamentos.
	int noperacoes[2]; //variável utilizada na alocação dinâmica feita pelo array de ponteiros 'historico'.
public:
	Conta(string nome = "", int numero = 0, string senha = "123456", float saldo = 0); //Construtor default.
	Conta(Conta &); //Construtor de cópia
	~Conta(); //Destrutor
	
	
	string getSenha(){
		return this->senha;
	}

	//função que realiza um pagamento de uma conta para outra.
	//void pagamento();
	
	//funcão que realiza um saque de uma conta.
	//void saque();
	
	void info(); //mostra as informações da conta.
	int verificaSenha(const string &); //verifica se a senha dada é a senha da conta.
	void registraOperacao(int tipo,float valor); //registra uma operação na matriz(array de ponteiros) 'historico'.
	void imprimeHistorico();//imprime o histórico de operações da conta.
	//Função auxiliar utilizada para verifica se uma string dada é formada por números, para validar os atributos nome e senha.
	bool stringDigitos(const string &); 
};

#endif // CONTA_H
