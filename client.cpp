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

//Interface gráfica do projeto

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
        //cout<<"5 - [+$] Solicitar cartão de Crédito" <<endl;
        cin >> operacao;

        acao(operacao);

    }while(operacao);
}

//função responsável pela ação que será selecionada pelo usuário utilizando
//a estrutura switch case para as 'n' opções disponíveis

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
                cout << "Opção inválida! Por favor, digite uma opção válida!\n" <<endl;
    }

}

//função responsável pelo cadastro de cliente para saber se
//o mesmo pode obter um cartão de crédito baseado em dados como
//nome, idade, cpf e renda mensal

void Client::cadastrarCliente()
{
	char nome[100];
	double cpf;
	int idade;
	int renda;
	
    cout <<"Digite o seu nome completo: "<<endl;
    cin >> nome;
    
    cout <<"Informe seu CPF (sem ponto ou traço): "<<endl;
    cin >> cpf;
    
    cout <<"Digite a sua idade: "<<endl;
    cin >> idade;
    
    cout <<"Qual a sua renda mensal? "<<endl;
    cin >> renda;
    
	if((idade >= 18) && (renda >= 1200)) {
		cout<<"Parabéns! Você está apto a solicitar um cartão de crédito!"<<endl;
        }
    else {
    	cout <<"Infelizmente você não atende aos requisitos para possuir um cartão!"<<endl;
	}
        
}

//função responsável pela consulta de saldo

void Client::verSaldo()
{
    cout<<"\nSeu saldo atual é: R$" << dinheiro <<endl;
}

//função responsável pelo depósito de dinheiro,
//onde o valor armazenado é exibido a cada iteração

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
        cout<< "Valor inválido! Por favor, tente novamente!\n" <<endl;

}

//função de saque de dinheiro, onde o saque será armazenado na variável
//valor após cada iteração do programa, independente da quantidade de
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
        cout<<"Saldo insuficiente! Por favor, adicione saldo à conta para realizar esta operação!\n" <<endl;
}
