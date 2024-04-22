#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#endif // TESTS_H_INCLUDED

#include <iostream>
using namespace std;

//PARRA - 211020956

class TUCodigoPagamento {

    private:
        const static string CODIGO_VALIDO = "28273456";
        const static string CODIGO_TAMANHO_INVALIDO = "0992534"; //PODE SER MAIOR OU MENOR QUE 8
        const static string CODIGO_INVALIDO_PRIMEIRO_DIGITO = "09925345";
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
       const static string CODIGO_VALIDO = "CDB2E3FTV8X";
       const static string CODIGO_INVALIDO_MINUSCULA = "CDB2E3FTv8X";
       const static string CODIGO_INVALIDO_SIMBOLO = "CDB2$3FTV8X";
       const static string CODIGO_INVALIDO_TITULO = "CD32E3FTV8X";
       const static string CODIGO_TAMANHO_INVALIDO = "CD32E3FTV8";
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
        int FALHA = -1;
        int SUCESSO = 0;
        int run();
};
