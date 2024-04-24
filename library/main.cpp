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

    return 0;
}
