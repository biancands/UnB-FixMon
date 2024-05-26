
#include <iostream>
#include "entities.h"
#include "domains.h"
#include "tests.h"


using namespace std;

int main()
{

    TUDinheiro testeDinheiro;
    switch(testeDinheiro.run()){
        case TUDinheiro::SUCESSO: cout << "SUCESSO - DINHEIRO" << endl;
                                  break;
        case TUDinheiro::FALHA  : cout << "FALHA   - DINHEIRO" << endl;
                                  break;
    }

    TUSenha testeSenha;
    switch(testeSenha.run()){
        case TUSenha::SUCESSO: cout << "SUCESSO - SENHA" << endl;
                                  break;
        case TUSenha::FALHA  : cout << "FALHA   - SENHA" << endl;
                                  break;
    }

    TUCodigoPagamento testeCodigoPay;
    switch(testeCodigoPay.run()){
        case TUCodigoPagamento::SUCESSO: cout << "SUCESSO - CODIGO PAGAMENTO" << endl;
                                  break;
        case TUCodigoPagamento::FALHA  : cout << "FALHA   - CODIGO PAGAMENTO" << endl;
                                  break;
    };

    TUCodigoTitulo testeCodigoTitulo;
    switch(testeCodigoTitulo.run())
    {
        case TUCodigoTitulo::SUCESSO:
            cout << "SUCESSO - CODIGO TITULO" << endl;
            break;
        case TUCodigoTitulo::FALHA:
            cout << "FALHA - CODIGO TITULO" << endl;

    }

    TUEstado testeEstado;
    switch(testeEstado.run()){
        case TUEstado::SUCESSO: cout << "SUCESSO - ESTADO" << endl;
                                  break;
        case TUEstado::FALHA  : cout << "FALHA - ESTADO" << endl;
                                  break;
    }

    TUCPF testeCPF;
    switch(testeCPF.run()){
        case TUCPF::SUCESSO: cout << "SUCESSO - CPF" << endl;
                                  break;
        case TUCPF::FALHA  : cout << "FALHA - CPF" << endl;
                                  break;
    }

    TUData testeA;
    TUPercentual testeB;

    switch(testeA.run()){
        case TUData::SUCESSO: cout << "SUCESSO - DATA" << endl ;
                                break;

        case TUData::FALHA  : cout << "FALHA   - DATA" << endl;
                               break;
    }

    switch(testeB.run()){
        case TUPercentual::SUCESSO: cout << "SUCESSO - PERCENTUAL" << endl ;
                                break;

        case TUPercentual::FALHA  : cout << "FALHA   - PERCENTUAL" << endl;
                               break;
    }

    TUNome testeNome;
    switch(testeNome.run()){
        case TUNome::SUCESSO: cout << "SUCESSO - NOME"<<endl;
            break;
        case TUNome::FALHA: cout<< "FALHA - NOME"<<endl;
    }


    TUSetor testeSetor;
    switch(testeSetor.run()){
        case TUSetor::SUCESSO: cout<<"SUCESSO - SETOR"<<endl;
            break;
        case TUSetor::FALHA: cout<<"FALHA - SETOR"<<endl;
            break;
    }


    TUConta testeConta;
    switch(testeConta.run()){
        case TUConta::SUCESSO: cout << "SUCESSO - CONTA" << endl;
                                break;
        case TUConta::FALHA: cout << "FALHA   - CONTA" << endl;
                                break;
    }




    return 0;
}
