#ifndef CTRL_SERVICO_H_INCLUDED
#define CTRL_SERVICO_H_INCLUDED

#include "interfaces.h"
#include "domains.h"
#include "containers.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

//231013583
class CntrISInvestimento : public ISInvestimento {
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

#endif // CTRL_SERVICO_H_INCLUDED
