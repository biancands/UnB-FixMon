#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Forward declarations
class ISAutenticacao;
class IAAutenticacao;


//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de apresenta��o.

/**
 * \class IAAutenticacao
 * \brief Interface para opera��es de autentica��o de usu�rios.
 *
 * Esta interface define o contrato para opera��es de autentica��o de usu�rios,
 * utilizando CPF e senha como identificadores. � implementada pela controladora
 * CntrIAAutenticacao, que ent�o delega o servi�o para a interface de servi�o ISAutenticacao.
 */

//200040979
class IAAutenticacao {
public:
    // M�todos para apresenta��o de ISAutenticacao.

    /**
     * \brief Autentica um usu�rio no sistema.
     * \param cpf Objeto CPF contendo o identificador do usu�rio.
     * \param senha Objeto Senha contendo a senha do usu�rio.
     * \return bool Indicador de sucesso ou falha da autentica��o.
     *
     * Este m�todo deve ser chamado para iniciar o processo de autentica��o de um usu�rio
     * no sistema. Ele � respons�vel por coletar as informa��es passadas pelo usu�rio
     * e enviar os dados para a camada de servi�o.
     */
    virtual bool autenticar(CPF*, Senha*) = 0;

    /**
     * \brief Estabelece a liga��o com a controladora da camada de servi�o.
     * \param cntrISAutenticacao Ponteiro para a controladora da camada de servi�o.
     *
     * Este m�todo deve ser chamado para estabelecer a liga��o entre a camada de
     * apresenta��o e a camada de servi�o, permitindo a comunica��o entre elas.
     */
    virtual void setCntrISAutenticacao(ISAutenticacao*) = 0;

    /**
     * \brief M�todo destrutor virtual (IAAutenticacao).
     */
    virtual ~IAAutenticacao() {}
};


//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de servi�o.

/**
 * \class ISAutenticacao
 * \brief Interface para opera��es de autentica��o na camada de servi�o.
 *
 * Esta interface define o contrato para opera��es de autentica��o de usu�rios
 * na camada de servi�o, utilizando CPF e senha como identificadores. � implementada
 * por uma classe de servi�o que executa a l�gica de autentica��o.
 */

//200040979
class ISAutenticacao {
public:
    /**
     * \brief Autentica um usu�rio no sistema.
     * \param cpf Objeto CPF contendo o identificador do usu�rio.
     * \param senha Objeto Senha contendo a senha do usu�rio.
     * \return bool Indicador de sucesso ou falha da autentica��o.
     *
     * Este m�todo deve ser chamado para realizar a autentica��o de um usu�rio no
     * sistema. Ele � respons�vel por verificar as credenciais do usu�rio na base de dados
     * ou sistema de autentica��o.
     */
    virtual bool autenticar(const CPF&, const Senha&) = 0;

    /**
     * \brief M�todo destrutor virtual (ISAutenticacao).
     */
    virtual ~ISAutenticacao() {}
};

#endif // INTERFACES_H_INCLUDED
