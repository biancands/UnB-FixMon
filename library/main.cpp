#include <iostream>
#include "entities.h"
#include "tests.h"

using namespace std;

int main()
{
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
}
