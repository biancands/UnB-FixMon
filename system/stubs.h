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

//231013583
class StubISInvestimento : public ISInvestimento {
public:
    bool criar(const Titulo&);
    bool ler(Titulo*);
    bool atualizar(const Titulo&);
    bool excluir(const CodigoTitulo&);
    bool criar(const Pagamento&);
    bool ler(Pagamento*);
    bool atualizar(const Pagamento&);
    bool excluir(const CodigoPagamento&);
};

#endif // STUBS_H_INCLUDED
