#ifndef CTRL_APRESENTACAO_H_INCLUDED
#define CTRL_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "domains.h"
#include "entities.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

//20040979
class CntrIAAutenticacao : public IAAutenticacao {
private:
    ISAutenticacao *cntrISAutenticacao;
    void apresentarOpcoes();
    void apresentarOpcoesPosAutenticacao();
public:
    bool autenticar(CPF*, Senha*);
    void executar();
    void setCntrISAutenticacao(ISAutenticacao*);
};

inline void CntrIAAutenticacao::setCntrISAutenticacao(ISAutenticacao *cntrISAutenticacao) {
    this->cntrISAutenticacao = cntrISAutenticacao;
}

//231035105
class CntrIAConta : public IAConta {
private:
    ISConta *cntrISConta;
public:
    void criar() override;
    int executar(const CPF&) override;
    void setCntrISConta(ISConta*);
};

inline void CntrIAConta::setCntrISConta(ISConta *cntrISConta) {
    this->cntrISConta = cntrISConta;
}

//231013583
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
