#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "domains.h"

//222014142
class TUEstado{
private:
    constexpr static char* VALOR_VALIDO   = "Previsto";
    constexpr static char* VALOR_INVALIDO = "previsto";
    Estado *status;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

//222014142
class TUCPF{
private:
    constexpr static char* VALOR_VALIDO   = "135.773.667-37";
    constexpr static char* VALOR_INVALIDO1 = "135.773.667-36";
    constexpr static char* VALOR_INVALIDO2 = "135.773.667.37";
    CPF *cpf;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha1();
    void testarCenarioFalha2();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

#endif // TESTS_H_INCLUDED

