#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

class ISInvestimento {
public:
    // M�todos para opera��es CRUD em t�tulos.

    virtual bool criar(const Titulo&) = 0;                          // M�todo para criar um novo t�tulo.
    virtual bool ler(Titulo*) = 0;                                  // M�todo para ler um t�tulo existente.
    virtual bool atualizar(const Titulo&) = 0;                      // M�todo para atualizar um t�tulo existente.
    virtual bool excluir(const CodigoTitulo&) = 0;                  // M�todo para excluir um t�tulo.

    // M�todos para opera��es CRUD em pagamentos.

    virtual bool criar(const Pagamento&) = 0;                       // M�todo para criar um novo pagamento.
    virtual bool ler(Pagamento*) = 0;                               // M�todo para ler um pagamento existente.
    virtual bool atualizar(const Pagamento&) = 0;                   // M�todo para atualizar um pagamento existente.
    virtual bool excluir(const CodigoPagamento&) = 0;               // M�todo para excluir um pagamento.

    virtual ~ISInvestimento(){}                                     // M�todo destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
