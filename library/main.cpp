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

    return 0;
}
