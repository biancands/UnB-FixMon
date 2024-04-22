#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "domains.h"

using namespace std;

//231013583
class TUDinheiro {
private:
    constexpr static double VALOR_VALIDO   = 500000.00;
    constexpr static double VALOR_INVALIDO = 1000500.00;
    constexpr static double VALOR_NEGATIVO = -100.00;
    Dinheiro *dinheiro;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void testarCenarioNegativo();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

//231013583
class TUSenha {
private:
    const static int VALOR_VALIDO   = 102469;
    const static int VALOR_DUPLICADO = 119843;
    const static int VALOR_ZERO_INICIO = 012345;
    const static int VALOR_CRESCENTE = 123456;
    const static int VALOR_DECRESCENTE = 654321;
    Senha *senha;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioDuplicado();
    void testarCenarioZeroInicio();
    void testarCenarioCrescente();
    void testarCenarioDecrescente();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};


#endif // TESTS_H_INCLUDED
