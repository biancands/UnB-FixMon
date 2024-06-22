/**
 * @file tests.h
 * @brief Definições das classes que representam os testes dos domínios e entidades.
 *
 * Desenvolvedores:
 * - BIANCA N. SILVA
 * - FABIO L. B. PARRA
 * - DANILO S. SILVA
 * - MARCELO J. C. ESPINDOLA
 * - JORGE L. C. A. SILVA
 */

 /**
 * @mainpage Projeto UnB-FixMon
 *
 * @section intro_sec Introdução
 *
 * Este é o projeto UnB-FixMon.
 *
 * @section repo_sec Repositório
 *
 * O repositório do projeto pode ser encontrado em: [https://github.com/biancands/UnB-FixMon](https://github.com/biancands/UnB-FixMon)
 */

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "domains.h"
#include "entities.h"

using namespace std;

//======================================= TESTES DOMINIO =========================================================

//231035105
class TUNome
{
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

//231035105
class TUSetor
{
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

//231013583
class TUDinheiro
{
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
class TUSenha
{
private:
    const string VALOR_VALIDO   = "102469";
    const string VALOR_DUPLICADO = "119843";
    const string VALOR_ZERO_INICIO = "012345";
    const string VALOR_CRESCENTE = "123456";
    const string VALOR_DECRESCENTE = "654321";
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

//211020956
class TUCodigoPagamento
{
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

//211020956
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

//222014142
class TUEstado
{
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
class TUCPF
{
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

//200040979
class TUData
{
private:
    static const std::string DATA_VALIDA;
    static const std::string DATA_INVALIDA;

    Data* data;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;
    int run();
};

//200040979
class TUPercentual
{
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

//======================================== TESTES ENTIDADES ============================================================

//200040979
class TUConta
{
private:
    static constexpr const char* CPF_VALIDO = "135.773.667-37";
    const string PRIMEIRO_NOME_VALIDO = "Jorge";
    const string SOBRE_NOME_VALIDO = "Lucas";
    const string SENHA_VALIDO = "102469";

    Conta *conta;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

//211020956
class TUPagamento
{
    private:

        const string codigoPagamentoValido = "33213098";
        const string dataValida = "12-03-2023";
        const static int percentualValido = 50;
        const string estadoValido = "Previsto";
        Pagamento *pagamento;
        int estadoTest;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

//231035105
class TUTitulo
{
private:
    const string CODIGO_VALIDO = "CDB2E3FTV8X";
    const string PRIMEIRO_NOME_VALIDO = "Jorge";
    const string SOBRE_NOME_VALIDO = "Lucas";
    const string SETOR_VALIDO = "Agricultura";
    const string DATA_VALIDA = "03-04-2024";
    const double VALOR_VALIDO = 500.00;
    Titulo *titulo;
    int estadoTest;
    void setup();
    void teardown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();

};

#endif // TESTS_H_INCLUDED
