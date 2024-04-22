#include "tests.h"
#include "entities.h"
#include <iostream>
#include "domains.h"

using namespace std;

void TUEstado::setUp(){
    status = new Estado();
    estado = SUCESSO;
}

void TUEstado::tearDown(){
    delete status;
}

void TUEstado::testarCenarioSucesso(){
    try{
        status-> setEstado(VALOR_VALIDO);
        if(status->getEstado() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEstado::testarCenarioFalha(){
    try{
        status-> setEstado(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (status->getEstado() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEstado::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUCPF::setUp(){
    cpf = new CPF();
    estado = SUCESSO;
}

void TUCPF::tearDown(){
    delete cpf;
}

void TUCPF::testarCenarioSucesso(){
    try{
        cpf->setCPF(VALOR_VALIDO);
        if(cpf->getCPF() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha1(){
    try{
        cpf->setCPF(VALOR_INVALIDO1);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (cpf->getCPF() == VALOR_INVALIDO1)
            estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha2(){
    try{
        cpf->setCPF(VALOR_INVALIDO2);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (cpf->getCPF() == VALOR_INVALIDO2)
            estado = FALHA;
    }
}

int TUCPF::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha1();
    testarCenarioFalha2();
    tearDown();
    return estado;
}
