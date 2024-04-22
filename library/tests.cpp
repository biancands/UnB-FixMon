#include "tests.h"
#include "entities.h"

void TUCodigoPagamento::setUp(){
    codigo = new CodigoPagamento();
    estado = SUCESSO;
}

void TUCodigoPagamento::tearDown(){
    delete codigo;
}

void TUCodigoPagamento::testCenarioCodValido(){

    try{
        codigo->setCodigo(CODIGO_VALIDO);
        if (codigo->getCodigo() != CODIGO_VALIDO)
        {
            estado = FALHA;
        }
        
    }
    catch(invalid_argument &e)
    {
        estado = FALHA;   
    }
}
void TUCodigoPagamento::testCenarioCodInvalidoPrimeiroDigito(){
    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_PRIMEIRO_DIGITO);
        estado=FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_PRIMEIRO_DIGITO)
        {
            estado=FALHA;
        }
    }
}

void TUCodigoPagamento::testCenarioCodTamanhoInvalido(){
    try
    {
        codigo->setCodigo(CODIGO_TAMANHO_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &e)
    {
        if (codigo->getCodigo() == CODIGO_TAMANHO_INVALIDO)
        {
            estado=FALHA;
        }
    }
    
}

int TUCodigoPagamento::run(){
    setUp();
    testCenarioCodValido();
    testCenarioCodInvalidoPrimeiroDigito();
    testCenarioCodTamanhoInvalido();
    return estado;
}

void TUCodigoTitulo::setUp(){
    codigo = new CodigoTitulo();
    estado = SUCESSO;
}

void TUCodigoTitulo::tearDown(){
    delete codigo;
}

void TUCodigoTitulo::testCodValido(){

    try
    {
        codigo->setCodigo(CODIGO_VALIDO);
        if (codigo->getCodigo() != CODIGO_VALIDO)
        {
            estado = FALHA;
        }    
    }
    catch(invalid_argument &e)
    {
        estado=FALHA;
    }
    
}

void TUCodigoTitulo::testCodInvalidoMinuscula(){

    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_MINUSCULA);
        estado = FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_MINUSCULA)
            estado=FALHA;
    }
    
}


void TUCodigoTitulo::testCodInvalidoSimbolo(){

    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_SIMBOLO);
        estado = FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_SIMBOLO)
            estado=FALHA;
        
    }
    
}

void TUCodigoTitulo::testCodTamanhoInvalido(){

    try
    {
        codigo->setCodigo(CODIGO_TAMANHO_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &e)
    {
        if (codigo->getCodigo() == CODIGO_TAMANHO_INVALIDO)
            estado = FALHA;
        
    }
    
}


void TUCodigoTitulo::testCodInvalidoTitulo(){

    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_TITULO);
        estado = FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_TITULO)
            estado = FALHA;
        
    }
    
}

int TUCodigoTitulo::run(){

    setUp();
    testCodValido();
    testCodInvalidoMinuscula();
    testCodInvalidoTitulo();
    testCodInvalidoSimbolo();
    testCodTamanhoInvalido();
    tearDown();
    return estado;
}