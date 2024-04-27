#include "domains.h"
#include <iostream>
#include "tests.h"
#include <string>

const std::string TUData::DATA_VALIDA = "20-10-2010";
const std::string TUData::DATA_INVALIDA = "34-16-2599";

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioSucesso(){
    try{
        data->validarData(DATA_VALIDA);
        if (data->getDia() != VALOR_DIA_VALIDO || data->getMes() != VALOR_MES_VALIDO || data->getAno() != VALOR_ANO_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}


void TUData::testarCenarioFalha(){
    try{
        data->validarData(DATA_INVALIDA);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (data->getDia() == VALOR_DIA_INVALIDO && data->getMes() == VALOR_MES_INVALIDO && data->getAno() == VALOR_ANO_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUData::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//__________________________________

void TUPercentual::setUp(){
    percentual = new Percentual();
    estado = SUCESSO;
}

void TUPercentual::tearDown(){
    delete percentual;
}

void TUPercentual::testarCenarioSucesso(){
    try{
        percentual->setValor(VALOR_VALIDO);
        if (percentual->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUPercentual::testarCenarioFalha(){
    try{
        percentual->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (percentual->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}


int TUPercentual::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}








