#ifndef CTRL_APRESENTACAO_H_INCLUDED
#define CTRL_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "../library/domains.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

#define CLR_SCR system("cls");

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

#endif // CTRL_APRESENTACAO_H_INCLUDED
