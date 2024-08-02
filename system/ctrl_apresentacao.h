#ifndef CTRL_APRESENTACAO_H_INCLUDED
#define CTRL_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "../library/domains.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class CntrIAConta : public IAConta{
private:
    ISConta *cntrISConta;
public:
    bool criar(Conta);
    bool ler(Conta);
    bool atualizar(Conta);
    bool excluir(const CPF&);
    void setCntrISConta(ISConta* cntrISConta);
};

//void CntrIAConta::setCntrISConta(ISConta* cntrISConta){
//    this -> cntrISConta = cntrISConta;
//}

#endif // CTRL_APRESENTACAO_H_INCLUDED
