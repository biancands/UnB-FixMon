#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h"
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Declarações adiantadas (forward declaration).

class ISAutenticacao;
class ISConta;
class ISInvestimento;

//-----------------------------------------------------------------------------------
// Declaração de interface da camada de apresentação.

/**
 * \class IAAutenticacao
 * \brief Interface para operações de autenticação de usuários.
 *
 * Esta interface define o contrato para operações de autenticação de usuários,
 * utilizando CPF e senha como identificadores. É implementada pela controladora
 * CntrIAAutenticacao, que então delega o serviço para a interface de serviço ISAutenticacao.
 */

//200040979
class IAAutenticacao {
public:
    // Métodos para apresentação de ISAutenticacao.

    /**
     * \brief Autentica um usuário no sistema.
     * \param cpf Objeto CPF contendo o identificador do usuário.
     * \param senha Objeto Senha contendo a senha do usuário.
     * \return bool Indicador de sucesso ou falha da autenticação.
     *
     * Este método deve ser chamado para iniciar o processo de autenticação de um usuário
     * no sistema. Ele é responsável por coletar as informações passadas pelo usuário
     * e enviar os dados para a camada de serviço.
     */
    virtual bool autenticar(CPF*, Senha*) = 0;

    /**
     * \brief Estabelece a ligação com a controladora da camada de serviço.
     * \param cntrISAutenticacao Ponteiro para a controladora da camada de serviço.
     *
     * Este método deve ser chamado para estabelecer a ligação entre a camada de
     * apresentação e a camada de serviço, permitindo a comunicação entre elas.
     */
    virtual void setCntrISAutenticacao(ISAutenticacao*) = 0;

    /**
     * \brief Método destrutor virtual (IAAutenticacao).
     */
    virtual ~IAAutenticacao() {}
};

/**
 * \class IAConta
 * \brief Interface para operações de criação e execução em contas.
 *
 * Esta interface define o contrato para operações de criação de contas e execução
 * de ações relacionadas a contas, utilizando o CPF como identificador. É
 * implementada pela controladora CntrIAConta, que então
 * delega o serviço para a interface de serviço ISConta.
 */

 //211020956
class IAConta {
public:
    // Métodos para apresentação de ISConta.
    /**
     * \brief Cria uma nova conta no sistema.
     *
     * Este método deve ser chamado para iniciar o processo de criação de uma nova
     * conta no sistema. Ele é responsável por coletar as informações passadas pelo usuário
     * e enviar os dados para a camada de serviço.
     */
    virtual void criar();
    /**
     * \brief Executa ações relacionadas a uma conta existente.
     * \param cpf Objeto CPF contendo o identificador da conta.
     * \return int Código de retorno indicando o resultado da operação.
     *
     * Este método deve ser chamado para executar ações em uma conta existente,
     * identificada pelo CPF fornecido. O código de retorno indica o sucesso ou
     * falha da operação.
     */
    virtual int executar(const CPF&) = 0;

    /**
     * \brief Estabelece a ligação com a controladora da camada de serviço.
     * \param cntrISConta Ponteiro para a controladora da camada de serviço.
     *
     * Este método deve ser chamado para estabelecer a ligação entre a camada de
     * apresentação e a camada de serviço, permitindo a comunicação entre elas.
     */
    virtual void setCntrISConta(ISConta*) = 0;

    /**
     * \brief Metodo Destrutor virtual (IAConta).
     */
    virtual ~IAConta(){};
};

/**
 * \class IAInvestimento
 * \brief Interface para operações de execução relacionadas a investimentos.
 *
 * Esta interface define o contrato para a execução de operações relacionadas a investimentos,
 * utilizando o CPF como identificador. É implementada pela controladora CntrIAInvestimento, que então
 * delega o serviço para a interface de serviço correspondente.
 */

//231013583
class IAInvestimento {
public:
    /**
     * \brief Executa ações relacionadas a uma conta de investimentos existente.
     * \param cpf Objeto CPF contendo o identificador da conta.
     *
     * Este método deve ser chamado para executar ações em uma conta de investimentos existente,
     * identificada pelo CPF fornecido. A implementação desse método deve definir as operações
     * específicas a serem realizadas.
     */
    virtual void executar(const CPF&) = 0;

    /**
     * \brief Estabelece a ligação com a controladora da camada de serviço.
     * \param CntrISInvestimento Ponteiro para a controladora da camada de serviço.
     *
     * Este método deve ser chamado para estabelecer a ligação entre a camada de
     * apresentação e a camada de serviço, permitindo a comunicação entre elas.
     */
    virtual void setCntrISInvestimento(ISInvestimento*) = 0;

    /**
     * \brief Destrutor virtual.
     *
     * O destrutor virtual garante que os recursos alocados pela classe derivada sejam
     * corretamente liberados quando a interface for destruída.
     */
    virtual ~IAInvestimento() {}
};

//-----------------------------------------------------------------------------------
// Interface da camada de serviço para operações de investimento.

/**
 * \class ISAutenticacao
 * \brief Interface para operações de autenticação de usuários.
 *
 * Esta interface define o contrato para a operação de autenticação de usuários,
 * ela é utilizada pelas controladoras da camada de apresentação para intermediar
 * as operações de autenticação entre o usuário e os dados persistidos.
 */

//222014142
//200040979
class ISAutenticacao {
public:
    /**
     * \brief Autentica um usuário no sistema.
     * \param cpf String contendo o CPF do usuário.
     * \param senha String contendo a senha do usuário.
     * \return bool Retorna verdadeiro se a autenticação foi bem-sucedida.
     */
    virtual bool autenticar(const string& CPF, const string& Senha) = 0;

    /**
     * \brief Destrutor virtual.
     */
    virtual ~ISAutenticacao() {}
};

/**
 * \class ISConta
 * \brief Interface para operações CRUD em contas.
 *
 * Esta interface define o contrato para operações CRUD em contas,
 * ela é utilizada pelas
 * controladoras da camada de apresentação para intermediar as operações entre
 * o usuário e os dados persistidos.
 */

//231035105
class ISConta{
public:
    // Métodos para operações CRUD em contas
    /**
     * \brief Cria uma nova conta no sistema
     * \param conta Objeto Conta contendo os dados da conta a ser criada.
     * \return bool Retorna verdadeiro se a conta foi criada com sucesso.
     */
    virtual bool criar(const Conta&) = 0;
    /**
     * \brief Lê uma conta existente no sistema.
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
     * \brief Exclui um CPF do sistema usando um código de identificação.
     * \param cpf Objeto CPF contendo o CPF da conta.
     * \return bool Retorna verdadeiro se o CPF foi excluido com sucesso.
     */
    virtual bool excluir(const CPF&) = 0;

};


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
