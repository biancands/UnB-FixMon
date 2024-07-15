#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Interface da camada de servi�o para opera��es de investimento.

/**
 * \class ISInvestimento
 * \brief Interface para opera��es CRUD em t�tulos e pagamentos.
 *
 * Esta interface define o contrato para opera��es CRUD em t�tulos e pagamentos,
 * ela � utilizada pelas
 * controladoras da camada de apresenta��o para intermediar as opera��es entre
 * o usu�rio e os dados persistidos.
 */

 //231013583
class ISInvestimento {
public:
    // M�todos para opera��es CRUD em t�tulos.

    /**
     * \brief Cria um novo t�tulo no sistema.
     * \param titulo Objeto Titulo contendo os dados do t�tulo a ser criado.
     * \return bool Retorna verdadeiro se o t�tulo foi criado com sucesso.
     */
    virtual bool criar(const Titulo&) = 0;

    /**
     * \brief L� um t�tulo existente no sistema.
     * \param titulo Ponteiro para um objeto Titulo para armazenar os dados lidos.
     * \return bool Retorna verdadeiro se os dados foram lidos com sucesso.
     */
    virtual bool ler(Titulo*) = 0;

    /**
     * \brief Atualiza um t�tulo existente no sistema.
     * \param titulo Objeto Titulo contendo os novos dados do t�tulo.
     * \return bool Retorna verdadeiro se o t�tulo foi atualizado com sucesso.
     */
    virtual bool atualizar(const Titulo&) = 0;

    /**
     * \brief Exclui um t�tulo do sistema usando um c�digo de identifica��o.
     * \param codigo Objeto CodigoTitulo contendo o identificador do t�tulo.
     * \return bool Retorna verdadeiro se o t�tulo foi exclu�do com sucesso.
     */
    virtual bool excluir(const CodigoTitulo&) = 0;

    // M�todos para opera��es CRUD em pagamentos.

    /**
     * \brief Cria um novo pagamento no sistema.
     * \param pagamento Objeto Pagamento contendo os dados do pagamento a ser criado.
     * \return bool Retorna verdadeiro se o pagamento foi criado com sucesso.
     */
    virtual bool criar(const Pagamento&) = 0;

    /**
     * \brief L� um pagamento existente no sistema.
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
     * \brief Exclui um pagamento do sistema usando um c�digo de identifica��o.
     * \param codigo Objeto CodigoPagamento contendo o identificador do pagamento.
     * \return bool Retorna verdadeiro se o pagamento foi exclu�do com sucesso.
     */
    virtual bool excluir(const CodigoPagamento&) = 0;

    /**
     * \brief Destrutor virtual.
     */
    virtual ~ISInvestimento(){}
};

#endif // INTERFACES_H_INCLUDED
