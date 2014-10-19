#include "Conta.h"

#include <string>
#include <conio.h>

using namespace std;

//int qtdmax = 100;

ostream &operator << (ostream &output,const Conta &c){
	output << c.numero;
	
	return output;
}

Conta::Conta(string nome, int numero, string senha, float saldo)
:nome(nome), numero(numero), senha(senha), saldo(saldo)
{
	if (stringDigitos(nome))
		this->nome = "";
	else
		this->nome = nome;
	
	if (numero < 0)
		this->numero = 0;
	else
		this->numero = numero;
	
	if (stringDigitos(senha) && senha.size() == 6)
		this->senha = senha;
	else
		this->senha = "123456";
	
	if (saldo < 0)
		this->saldo = 0;
	else
		this->saldo = saldo;
		
	this->noperacoes[0] = 0;
	this->noperacoes[1] = 0;
	
	this->historico[0] = NULL;
	this->historico[1] = NULL;
}

Conta::Conta(Conta &c){//falta fazer a cópia do ponteiro!
	this->nome = c.nome;
	this->numero = c.numero;
	this->senha = c.senha;
	this->saldo = c.saldo;
	
	this->noperacoes[0] = c.noperacoes[0];
	this->noperacoes[1] = c.noperacoes[1];
	
	//"Cópia" dos ponteiros
	int i;
	
	this->historico[0] = new float [c.noperacoes[0]];
	for (i = 0;i < c.noperacoes[0];i++)
		this->historico[0][i] = c.historico[0][i];
	
	this->historico[1] = new float [c.noperacoes[1]];
	for (i = 0;i < c.noperacoes[1];i++)
		this->historico[1][i] = c.historico[1][i];
}

Conta::~Conta()
{
	delete [] this->historico[0];
	delete [] this->historico[1];
}

Conta Conta::operator =(const Conta &c){
	this->nome = c.nome;
	this->numero = c.numero;
	this->senha = c.senha;
	this->saldo = c.saldo;
	
	this->noperacoes[0] = c.noperacoes[0];
	this->noperacoes[1] = c.noperacoes[1];
	
	//"Cópia" dos ponteiros
	int i;
	
	this->historico[0] = new float [c.noperacoes[0]];
	for (i = 0;i < c.noperacoes[0];i++)
		this->historico[0][i] = c.historico[0][i];
	
	this->historico[1] = new float [c.noperacoes[1]];
	for (i = 0;i < c.noperacoes[1];i++)
		this->historico[1][i] = c.historico[1][i];
	
	return *this;
}

void Conta::info(){
	cout<<endl<<"-- Informacoes da conta: ";
	cout<<endl<<" - Numero da conta: "<<this->numero;
	cout<<endl<<"Nome do proprietario: "<<this->nome;
	cout<<endl<<"Saldo disponivel: "<<this->saldo;
}

int Conta::verificaSenha(const string &senha){
	return (this->senha == senha);
}

void Conta::registraOperacao(int tipo, float valor){
	//Se tipo == 0, a operação é saque. Se tipo == 1,a operação realizada é um pagamento.
	float *aux = new float[this->noperacoes[tipo]];
	int i;
	
	for (i = 0;i < noperacoes[tipo];i++)
		aux[i] = this->historico[tipo][i];
		
	delete [] this->historico[tipo];
	
	this->historico[tipo] = new float[++(this->noperacoes[tipo])];
	
	for (i = 0;i < noperacoes[tipo] - 1;i++)
		this->historico[tipo][i] = aux[i];
		
	this->historico[tipo][this->noperacoes[tipo] - 1] = valor;
		
	delete [] aux;
}

void Conta::imprimeHistorico(){
	
	cout<<endl<<"Historico: ";
	
	if (this->noperacoes[0] == 0 && this->noperacoes[1] == 0)
		cout<<endl<<"Nenhuma operacao realizada na conta!!";
	else if(this->noperacoes[0] == 0 ){
		cout<<endl<<"Nenhum saque realizado na conta!!";
		cout<<endl<<" Pagamentos mais recentes: ";
		cout<<endl<<" "<<this->noperacoes[0]<<" "<<this->noperacoes[1];
		for (int i = this->noperacoes[1];i > 0;i--)
			cout<<endl<<"     R$"<<this->historico[1][i-1]<<" ";
	}
	else if(this->noperacoes[1] == 0 ){
		cout<<endl<<"Nenhum pagamento realizado na conta!!";
		cout<<endl<<" Saques mais recentes: ";
		for (int i = this->noperacoes[0];i > 0;i--)
			cout<<endl<<"     R$"<<this->historico[0][i-1]<<" ";
	}
	else{
		cout<<endl<<" Saques mais recentes: ";
		for (int i = this->noperacoes[0];i > 0;i--)
			cout<<endl<<"     R$"<<this->historico[0][i-1]<<" ";
	
		cout<<endl<<" Pagamentos mais recentes: ";
		for (int i = this->noperacoes[1];i > 0;i--)
			cout<<endl<<"     R$"<<this->historico[1][i-1]<<" ";
	}
}


bool Conta::stringDigitos(const string &s){
	if (s.empty())
		return false;
	for (unsigned int i = 0;i < s.size();i++)
		if (isdigit(s[i]) == 0)
			return false;
	
	return true;
}