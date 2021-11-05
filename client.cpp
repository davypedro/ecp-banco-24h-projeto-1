#include "Client.h"
#include <iostream>
#include <locale>

#include <string>

using namespace std;

Client::Client()
{
    dinheiro = 0;
    menu();
}

//Interface gr�fica do projeto

void Client::menu()
{
	setlocale(LC_ALL, "portuguese");
    int operacao = 0;
    
    cout << "\t********** ECP BANK **********\n\n\n";

    do{
        cout<<"0 - [xx] Sair do Sistema\n" <<endl;
        cout<<"1 - [()] Cadastre-se aqui!\n" <<endl;
        cout<<"2 - [%$] Realizar consulta de saldo em conta!\n" <<endl;
        cout<<"3 - [$$] Depositar dinheiro!\n" <<endl;
        cout<<"4 - [-$] Sacar dinheiro!\n" <<endl;
        //cout<<"5 - [+$] Solicitar cart�o de Cr�dito" <<endl;
        cin >> operacao;

        acao(operacao);

    }while(operacao);
}

//fun��o respons�vel pela a��o que ser� selecionada pelo usu�rio utilizando
//a estrutura switch case para as 'n' op��es dispon�veis

void Client::acao(int operacao)
{
    switch(operacao)
    {
        case 0:
                cout << "Sistema encerrado!"<<endl;
                break;
                
        case 1:
                cadastrarCliente();
                break;        
                
        case 2:
                verSaldo();
                break;

        case 3:
                depositarDinheiro();
                break;

        case 4:
                sacarDinheiro();
                break;
        
        //case 5:
          //      solicitarCartao();
            //    break;

        default:
                cout << "Op��o inv�lida! Por favor, digite uma op��o v�lida!\n" <<endl;
    }

}

//fun��o respons�vel pelo cadastro de cliente para saber se
//o mesmo pode obter um cart�o de cr�dito baseado em dados como
//nome, idade, cpf e renda mensal

void Client::cadastrarCliente()
{
	char nome[100];
	double cpf;
	int idade;
	int renda;
	
    cout <<"Digite o seu nome completo: "<<endl;
    cin >> nome;
    
    cout <<"Informe seu CPF (sem ponto ou tra�o): "<<endl;
    cin >> cpf;
    
    cout <<"Digite a sua idade: "<<endl;
    cin >> idade;
    
    cout <<"Qual a sua renda mensal? "<<endl;
    cin >> renda;
    
	if((idade >= 18) && (renda >= 1200)) {
		cout<<"Parab�ns! Voc� est� apto a solicitar um cart�o de cr�dito!"<<endl;
        }
    else {
    	cout <<"Infelizmente voc� n�o atende aos requisitos para possuir um cart�o!"<<endl;
	}
        
}

//fun��o respons�vel pela consulta de saldo

void Client::verSaldo()
{
    cout<<"\nSeu saldo atual �: R$" << dinheiro <<endl;
}

//fun��o respons�vel pelo dep�sito de dinheiro,
//onde o valor armazenado � exibido a cada itera��o

void Client::depositarDinheiro()
{
    double valor;

    cout<< "Valor que deseja depositar: ";
    cin >> valor;

    if(valor > 0){
        dinheiro = dinheiro + valor;
        verSaldo();
    }
    else
        cout<< "Valor inv�lido! Por favor, tente novamente!\n" <<endl;

}

//fun��o de saque de dinheiro, onde o saque ser� armazenado na vari�vel
//valor ap�s cada itera��o do programa, independente da quantidade de
//vezes

void Client::sacarDinheiro()
{
    double valor;

    cout<< "Digite o valor que deseja sacar: ";
    cin >> valor;

    if(valor <= dinheiro){
        dinheiro = dinheiro - valor;
        verSaldo();
    }
    else
        cout<<"Saldo insuficiente! Por favor, adicione saldo � conta para realizar esta opera��o!\n" <<endl;
}
