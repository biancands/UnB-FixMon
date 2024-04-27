#ifndef TESTS_H
#define TESTS_H

#include "domains.h"
#include "entities.h"
#include <string>

using namespace std;

class TUData {
private:

    const static std::string DATA_VALIDA;
    const static std::string DATA_INVALIDA;

    const static int VALOR_DIA_VALIDO   = 20;   // Defini��o de constante para evitar n�mero m�gico.
    const static int VALOR_DIA_INVALIDO = 34;   // Defini��o de constante para evitar n�mero m�gico.

    const static int VALOR_MES_VALIDO   = 10;   // Defini��o de constante para evitar n�mero m�gico.
    const static int VALOR_MES_INVALIDO = 16;   // Defini��o de constante para evitar n�mero m�gico.

    const static int VALOR_ANO_VALIDO   = 2010;   // Defini��o de constante para evitar n�mero m�gico.
    const static int VALOR_ANO_INVALIDO = 2599;   // Defini��o de constante para evitar n�mero m�gico.



    Data *data;                             // Refer�ncia para unidade em teste.

    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


class TUPercentual {
private:
    const static int VALOR_VALIDO   = 2;
    const static int VALOR_INVALIDO = 300;

    Percentual *percentual;

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




#endif
