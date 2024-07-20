#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Declara��es adiantadas (forward declaration).

class ISAutenticacao;
class ISConta;
class ISInvestimento;

//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de apresenta��o.

/**
 * \class IAConta
 * \brief Interface para opera��es de cria��o e execu��o em contas.
 *
 * Esta interface define o contrato para opera��es de cria��o de contas e execu��o
 * de a��es relacionadas a contas, utilizando o CPF como identificador. �
 * implementada pela controladora CntrIAConta, que ent�o
 * delega o servi�o para a interface de servi�o ISConta.
 */

 //211020956
class IAConta {
public:
    // M�todos para apresenta��o de ISConta.
    /**
     * \brief Cria uma nova conta no sistema.
     *
     * Este m�todo deve ser chamado para iniciar o processo de cria��o de uma nova
     * conta no sistema. Ele � respons�vel por coletar as informa��es passadas pelo usu�rio
     * e enviar os dados para a camada de servi�o.
     */
    virtual void criar();
    /**
     * \brief Executa a��es relacionadas a uma conta existente.
     * \param cpf Objeto CPF contendo o identificador da conta.
     * \return int C�digo de retorno indicando o resultado da opera��o.
     *
     * Este m�todo deve ser chamado para executar a��es em uma conta existente,
     * identificada pelo CPF fornecido. O c�digo de retorno indica o sucesso ou
     * falha da opera��o.
     */
    virtual int executar(const CPF&) = 0;

    /**
     * \brief Estabelece a liga��o com a controladora da camada de servi�o.
     * \param cntrISConta Ponteiro para a controladora da camada de servi�o.
     *
     * Este m�todo deve ser chamado para estabelecer a liga��o entre a camada de
     * apresenta��o e a camada de servi�o, permitindo a comunica��o entre elas.
     */
    virtual void setCntrISConta(ISConta*) = 0;

    /**
     * \brief Metodo Destrutor virtual (IAConta).
     */
    virtual ~IAConta(){};
};

//-----------------------------------------------------------------------------------
// Interface da camada de servi�o para opera��es de investimento.

/**
 * \class ISAutenticacao
 * \brief Interface para opera��es de autentica��o de usu�rios.
 *
 * Esta interface define o contrato para a opera��o de autentica��o de usu�rios,
 * ela � utilizada pelas controladoras da camada de apresenta��o para intermediar
 * as opera��es de autentica��o entre o usu�rio e os dados persistidos.
 */

//222014142
class ISAutenticacao {
public:
    /**
     * \brief Autentica um usu�rio no sistema.
     * \param cpf String contendo o CPF do usu�rio.
     * \param senha String contendo a senha do usu�rio.
     * \return bool Retorna verdadeiro se a autentica��o foi bem-sucedida.
     */
    virtual bool autenticar(const string& CPF, const string& Senha) = 0;

    /**
     * \brief Destrutor virtual.
     */
    virtual ~ISAutenticacao() {}
};

/**
 * \class ISConta
 * \brief Interface para opera��es CRUD em contas.
 *
 * Esta interface define o contrato para opera��es CRUD em contas,
 * ela � utilizada pelas
 * controladoras da camada de apresenta��o para intermediar as opera��es entre
 * o usu�rio e os dados persistidos.
 */

//231035105
class ISConta{
public:
    // M�todos para opera��es CRUD em contas
    /**
     * \brief Cria uma nova conta no sistema
     * \param conta Objeto Conta contendo os dados da conta a ser criada.
     * \return bool Retorna verdadeiro se a conta foi criada com sucesso.
     */
    virtual bool criar(const Conta&) = 0;
    /**
     * \brief L� uma conta existente no sistema.
     * \param conta Ponteiro para um objeto Conta para armazenar os dados lidos.
     * \return bool Retorna verdadeiro se os dados foram lidos com sucesso.
     */
    virtual bool ler(Conta*) = 0;
    /**
     * \brief Atualiza uma conta existente no sistema.
     * \param conta Objeto Conta contendo os novos dados da conta.
     * \return bool Retorna verdadeiro se a conta foi atualizada com sucesso.
     */
    virtual bool atualizar(const Conta&) = 0;
    /**
     * \brief Exclui um CPF do sistema usando um c�digo de identifica��o.
     * \param cpf Objeto CPF contendo o CPF da conta.
     * \return bool Retorna verdadeiro se o CPF foi excluido com sucesso.
     */
    virtual bool excluir(const CPF&) = 0;

};


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
