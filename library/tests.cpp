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

