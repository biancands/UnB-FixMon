#ifndef CTRL_APRESENTACAO_H_INCLUDED
#define CTRL_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "domains.h"
#include "entities.h"

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

// Declaração da controladora CntrIAInvestimento
class CntrIAInvestimento : public IAInvestimento {
private:
    ISInvestimento *cntrISInvestimento;
public:
    void executar(const CPF&) override;
    void setCntrISInvestimento(ISInvestimento*) override;
};

void inline CntrIAInvestimento::setCntrISInvestimento(ISInvestimento *cntrISInvestimento) {
    this->cntrISInvestimento = cntrISInvestimento;
}
#endif
