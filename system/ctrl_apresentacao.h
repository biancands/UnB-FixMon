#ifndef CTRL_APRESENTACAO_H_INCLUDED
#define CTRL_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "domains.h"

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


//231035105
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
#endif
