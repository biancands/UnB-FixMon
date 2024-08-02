#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

class StubISAutenticacao : public ISAutenticacao {
public:
    const static int TRIGGER_FALHA = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    bool autenticar(const string&, const string&);
};

// Declaração do StubISInvestimento
class StubISInvestimento : public ISInvestimento {
public:
    bool criar(const Titulo&) override;
    bool ler(Titulo*) override;
    bool atualizar(const Titulo&) override;
    bool excluir(const CodigoTitulo&) override;
    bool criar(const Pagamento&) override;
    bool ler(Pagamento*) override;
    bool atualizar(const Pagamento&) override;
    bool excluir(const CodigoPagamento&) override;
};

#endif // STUBS_H_INCLUDED
