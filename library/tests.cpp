#include "tests.h"
#include "entities.h"

void TUDinheiro::setUp(){
    dinheiro = new Dinheiro();
    estado = SUCESSO;
}

void TUDinheiro::tearDown(){
    delete dinheiro;
}

void TUDinheiro::testarCenarioSucesso(){
    try{
        dinheiro->setValor(VALOR_VALIDO);
        if (dinheiro->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioFalha(){
    try{
        dinheiro->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (dinheiro->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

void TUDinheiro::testarCenarioNegativo(){
    try{
        dinheiro->setValor(VALOR_NEGATIVO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (dinheiro->getValor() == VALOR_NEGATIVO)
            estado = FALHA;
    }
}

int TUDinheiro::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    testarCenarioNegativo();
    tearDown();
    return estado;
}

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioDuplicado(){
    try{
        senha->setValor(VALOR_DUPLICADO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_DUPLICADO)
            estado = FALHA;
    }
}

void TUSenha::testarCenarioZeroInicio(){
    try{
        senha->setValor(VALOR_ZERO_INICIO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_ZERO_INICIO)
            estado = FALHA;
    }
}

void TUSenha::testarCenarioCrescente(){
    try{
        senha->setValor(VALOR_CRESCENTE);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_CRESCENTE)
            estado = FALHA;
    }
}

void TUSenha::testarCenarioDecrescente(){
    try{
        senha->setValor(VALOR_DECRESCENTE);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_DECRESCENTE)
            estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioDuplicado();
    testarCenarioZeroInicio();
    testarCenarioCrescente();
    testarCenarioDecrescente();
    tearDown();
    return estado;
}

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

