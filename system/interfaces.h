#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

/**
 * \class ISAutenticacao
 * \brief Interface para operações de autenticação de usuários.
 *
 * Esta interface define o contrato para a operação de autenticação de usuários,
 * ela é utilizada pelas controladoras da camada de apresentação para intermediar
 * as operações de autenticação entre o usuário e os dados persistidos.
 */

//222014142
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

#endif // INTERFACES_H_INCLUDED
