#ifndef CLIENT_H
#define CLIENT_H


class Client
{
    public:
        Client();
        void menu();
        void acao(int);
        void cadastrarCliente();
        void verSaldo();
        void depositarDinheiro();
        void sacarDinheiro();
        

    private:
        double dinheiro;
};

#endif // CLIENT_H
