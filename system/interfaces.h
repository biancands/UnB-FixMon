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


//-----------------------------------------------------------------------------------
// Declaração de interface da camada de serviço.

/**
 * \class ISAutenticacao
 * \brief Interface para operações de autenticação na camada de serviço.
 *
 * Esta interface define o contrato para operações de autenticação de usuários
 * na camada de serviço, utilizando CPF e senha como identificadores. É implementada
 * por uma classe de serviço que executa a lógica de autenticação.
 */

//200040979
class ISAutenticacao {
public:
    /**
     * \brief Autentica um usuário no sistema.
     * \param cpf Objeto CPF contendo o identificador do usuário.
     * \param senha Objeto Senha contendo a senha do usuário.
     * \return bool Indicador de sucesso ou falha da autenticação.
     *
     * Este método deve ser chamado para realizar a autenticação de um usuário no
     * sistema. Ele é responsável por verificar as credenciais do usuário na base de dados
     * ou sistema de autenticação.
     */
    virtual bool autenticar(const CPF&, const Senha&) = 0;

    /**
     * \brief Método destrutor virtual (ISAutenticacao).
     */
    virtual ~ISAutenticacao() {}
};

#endif // INTERFACES_H_INCLUDED
