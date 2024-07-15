#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Interface da camada de serviço para operações de investimento.

/**
 * \class ISInvestimento
 * \brief Interface para operações CRUD em títulos e pagamentos.
 *
 * Esta interface define o contrato para operações CRUD em títulos e pagamentos,
 * ela é utilizada pelas
 * controladoras da camada de apresentação para intermediar as operações entre
 * o usuário e os dados persistidos.
 */

 //231013583
class ISInvestimento {
public:
    // Métodos para operações CRUD em títulos.

    /**
     * \brief Cria um novo título no sistema.
     * \param titulo Objeto Titulo contendo os dados do título a ser criado.
     * \return bool Retorna verdadeiro se o título foi criado com sucesso.
     */
    virtual bool criar(const Titulo&) = 0;

    /**
     * \brief Lê um título existente no sistema.
     * \param titulo Ponteiro para um objeto Titulo para armazenar os dados lidos.
     * \return bool Retorna verdadeiro se os dados foram lidos com sucesso.
     */
    virtual bool ler(Titulo*) = 0;

    /**
     * \brief Atualiza um título existente no sistema.
     * \param titulo Objeto Titulo contendo os novos dados do título.
     * \return bool Retorna verdadeiro se o título foi atualizado com sucesso.
     */
    virtual bool atualizar(const Titulo&) = 0;

    /**
     * \brief Exclui um título do sistema usando um código de identificação.
     * \param codigo Objeto CodigoTitulo contendo o identificador do título.
     * \return bool Retorna verdadeiro se o título foi excluído com sucesso.
     */
    virtual bool excluir(const CodigoTitulo&) = 0;

    // Métodos para operações CRUD em pagamentos.

    /**
     * \brief Cria um novo pagamento no sistema.
     * \param pagamento Objeto Pagamento contendo os dados do pagamento a ser criado.
     * \return bool Retorna verdadeiro se o pagamento foi criado com sucesso.
     */
    virtual bool criar(const Pagamento&) = 0;

    /**
     * \brief Lê um pagamento existente no sistema.
     * \param pagamento Ponteiro para um objeto Pagamento para armazenar os dados lidos.
     * \return bool Retorna verdadeiro se os dados foram lidos com sucesso.
     */
    virtual bool ler(Pagamento*) = 0;

    /**
     * \brief Atualiza um pagamento existente no sistema.
     * \param pagamento Objeto Pagamento contendo os novos dados do pagamento.
     * \return bool Retorna verdadeiro se o pagamento foi atualizado com sucesso.
     */
    virtual bool atualizar(const Pagamento&) = 0;

    /**
     * \brief Exclui um pagamento do sistema usando um código de identificação.
     * \param codigo Objeto CodigoPagamento contendo o identificador do pagamento.
     * \return bool Retorna verdadeiro se o pagamento foi excluído com sucesso.
     */
    virtual bool excluir(const CodigoPagamento&) = 0;

    /**
     * \brief Destrutor virtual.
     */
    virtual ~ISInvestimento(){}
};

#endif // INTERFACES_H_INCLUDED
