#ifndef CTRL_APRESENTACAO_H_INCLUDED
#define CTRL_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "../library/domains.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class CntrIAAutenticacao : public IAAutenticacao {
private:
    ISAutenticacao *cntrISAutenticacao;
public:
    bool autenticar(CPF*, Senha*);
    void setCntrISAutenticacao(ISAutenticacao*);
};

void inline CntrIAAutenticacao::setCntrISAutenticacao(ISAutenticacao *cntrISAutenticacao){
    this->cntrISAutenticacao = cntrISAutenticacao;
}
#endif
