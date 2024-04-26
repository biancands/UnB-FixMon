#include "tests.h"
#include "entities.h"
#include <iostream>
using namespace std;
void TUNome::setUp(){
    nome = new Nome(PRIMEIRO_NOME_VALIDO, SOBRE_NOME_VALIDO);
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioSucesso() {
    try {
        nome ->setPrimeiroNome(PRIMEIRO_NOME_VALIDO);
        nome ->setSobreNome(SOBRE_NOME_VALIDO);
        if(nome->getPrimeiroNome() != PRIMEIRO_NOME_VALIDO || nome ->getSobreNome() != SOBRE_NOME_VALIDO)
            estado = FALHA;    
    }catch (exception& excecao){
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalhaPrimeiroNome(){
    try {
        nome -> setPrimeiroNome(PRIMEIRO_NOME_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao) {
        if(nome -> getPrimeiroNome() == PRIMEIRO_NOME_INVALIDO && !nome->validarNome()) {
            estado = FALHA;
        }      
    }
}

void TUNome::testarCenarioFalhaSobreNome(){
    try{
        nome -> setSobreNome(SOBRE_NOME_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao) {
        if (nome ->getSobreNome() == SOBRE_NOME_INVALIDO)
            estado = FALHA;
    }
}



int TUNome::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalhaPrimeiroNome();
    testarCenarioFalhaSobreNome();
    tearDown();
    return estado;
}



void TUSetor::setUp(){
    setor = new Setor(SETOR_VALIDO);
    estado = SUCESSO;
}

void TUSetor::teardown(){
    delete setor;
}

void TUSetor::testarSetorValido(){
    try{
        setor ->setSetorNome(SETOR_VALIDO);
        if (setor->getSetorNome() != SETOR_VALIDO)
            estado = FALHA;
    } catch (invalid_argument& excecao){
        estado = FALHA;
    }
}

void TUSetor::testarSetorInvalido(){
    try{
        setor ->setSetorNome(SETOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao){
        
    }
}

int TUSetor::run(){
    setUp();
    testarSetorValido();
    testarSetorInvalido();
    teardown();
    return estado;
}