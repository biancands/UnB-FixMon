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

    const static int VALOR_DIA_VALIDO   = 20;   // Definição de constante para evitar número mágico.
    const static int VALOR_DIA_INVALIDO = 34;   // Definição de constante para evitar número mágico.

    const static int VALOR_MES_VALIDO   = 10;   // Definição de constante para evitar número mágico.
    const static int VALOR_MES_INVALIDO = 16;   // Definição de constante para evitar número mágico.

    const static int VALOR_ANO_VALIDO   = 2010;   // Definição de constante para evitar número mágico.
    const static int VALOR_ANO_INVALIDO = 2599;   // Definição de constante para evitar número mágico.



    Data *data;                             // Referência para unidade em teste.

    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
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
