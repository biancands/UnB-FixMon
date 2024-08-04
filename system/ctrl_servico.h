#ifndef CTRL_SERVICO_H_INCLUDED
#define CTRL_SERVICO_H_INCLUDED

#include "interfaces.h"
#include "containers.h"

class CntrServicoAutenticacao : public ISAutenticacao {
public:
    bool autenticar(const string&, const string&);
};

class CntrServicoConta : public ISConta {
public:
    bool criar(const Conta&) override;
    bool ler(Conta*) override;
    bool atualizar(const Conta&) override;
    bool excluir(const CPF&) override;
};

#endif // CTRL_SERVICO_H_INCLUDED
