#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "../library/domains.h"
#include "../library/entities.h
#include <stdexcept>

using namespace std;

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

#endif // INTERFACES_H_INCLUDED
