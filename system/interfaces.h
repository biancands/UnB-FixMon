#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

class ISInvestimento {
public:
    // Métodos para operações CRUD em títulos.

    virtual bool criar(const Titulo&) = 0;                          // Método para criar um novo título.
    virtual bool ler(Titulo*) = 0;                                  // Método para ler um título existente.
    virtual bool atualizar(const Titulo&) = 0;                      // Método para atualizar um título existente.
    virtual bool excluir(const CodigoTitulo&) = 0;                  // Método para excluir um título.

    // Métodos para operações CRUD em pagamentos.

    virtual bool criar(const Pagamento&) = 0;                       // Método para criar um novo pagamento.
    virtual bool ler(Pagamento*) = 0;                               // Método para ler um pagamento existente.
    virtual bool atualizar(const Pagamento&) = 0;                   // Método para atualizar um pagamento existente.
    virtual bool excluir(const CodigoPagamento&) = 0;               // Método para excluir um pagamento.

    virtual ~ISInvestimento(){}                                     // Método destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
