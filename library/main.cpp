#include <iostream>
#include "entities.h"
#include "domains.h"
#include "tests.h"

using namespace std;

int main()
{
    TUEstado testeEstado;
    switch(testeEstado.run()){
        case TUEstado::SUCESSO: cout << "SUCESSO - Estado" << endl;
                                  break;
        case TUEstado::FALHA  : cout << "FALHA - Estado" << endl;
                                  break;
    }

    TUCPF testeCPF;
    switch(testeCPF.run()){
        case TUCPF::SUCESSO: cout << "SUCESSO - CPF" << endl;
                                  break;
        case TUCPF::FALHA  : cout << "FALHA - CPF" << endl;
                                  break;
    }
    return 0;
}
