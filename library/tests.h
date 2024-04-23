#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include <iostream>

#include "entities.h"
#include "domains.h"

using namespace std;

//PARRA - 211020956
class TUCodigoPagamento {

    private:
        const string CODIGO_VALIDO = "28273456";
        const string CODIGO_TAMANHO_INVALIDO = "0992534"; //PODE SER MAIOR OU MENOR QUE 8
        const string CODIGO_INVALIDO_PRIMEIRO_DIGITO = "09925345";
        CodigoPagamento *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testCenarioCodValido();
        void testCenarioCodTamanhoInvalido();
        void testCenarioCodInvalidoPrimeiroDigito();
    public:
        const static int FALHA = -1;
        const static int SUCESSO = 0;
        int run();
};

//PARRA - 211020956
class TUCodigoTitulo
{
    private:
       const string CODIGO_VALIDO = "CDB2E3FTV8X";
       const string CODIGO_INVALIDO_MINUSCULA = "CDB2E3FTv8X";
       const string CODIGO_INVALIDO_SIMBOLO = "CDB2$3FTV8X";
       const string CODIGO_INVALIDO_TITULO = "CD32E3FTV8X";
       const string CODIGO_TAMANHO_INVALIDO = "CD32E3FTV8";
       int estado;
       CodigoTitulo *codigo;
       void setUp();
       void tearDown();
       void testCodValido();
       void testCodInvalidoMinuscula();
       void testCodInvalidoSimbolo();
       void testCodInvalidoTitulo();
       void testCodTamanhoInvalido();

    public:
        const static int FALHA = -1;
        const static int SUCESSO = 0;
        int run();
};

#endif // TESTS_H_INCLUDED
