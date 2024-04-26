#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "domains.h"
using namespace std;

class TUNome{
private:
    const string PRIMEIRO_NOME_VALIDO = "Jorge";
    const string SOBRE_NOME_VALIDO = "Lucas";
    const string PRIMEIRO_NOME_INVALIDO = "123";
    const string SOBRE_NOME_INVALIDO = "123";
    
    Nome* nome;
    
    int estado;

    void setUp();
    void tearDown();

    void testarCenarioSucesso();
    void testarCenarioFalhaPrimeiroNome();
    void testarCenarioFalhaSobreNome();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();

};

class TUSetor{
private:
    const string SETOR_VALIDO = "Agricultura";
    const string SETOR_INVALIDO = "Aviao";

    Setor *setor;

    int estado;

    void setUp();
    void teardown();

    void testarSetorValido();
    void testarSetorInvalido();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();

};


#endif // TESTS_H_INCLUDED
