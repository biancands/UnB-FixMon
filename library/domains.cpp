#include "domains.h"

using namespace std;

void Estado::validar(string estado){
    if(!(estado == "Previsto" || estado == "Liquidado" || estado == "Inadimplente"))
        throw invalid_argument("Argumento invalido.");
}

void Estado::setEstado(string valor){
    validar(valor);
    this->valor = valor;
}

void CPF::validar(string cpf){
    int digito;
    int resto;
    int soma1 = 0;
    int soma2 = 0;
    int peso = 0;
    if(cpf.size() != 14){
            throw invalid_argument("CPF inválida! Não possui 14 carcteres.");
    }
    if(cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
            throw invalid_argument("CPF inválida! Pontuação errada.");
    }
    for (int i = 0; i < 14; i++){
        if(i == 3 || i == 7 || i == 11){continue;}
        else{
            if(!isdigit(cpf[i])){
                throw invalid_argument("CPF inválida! Não é digito.");
        }
            else if(i == 13){
                digito = cpf[i] - '0';
                resto = soma2 % 11;
                if(resto == 10){resto = 0;}
                if(resto != digito){
                        throw invalid_argument("CPF inválida!");
                }
            }else if(i == 12){
                digito = cpf[i] - '0';
                resto = soma1 % 11;
                if(resto == 10){resto = 0;}
                if(resto != digito){
                        throw invalid_argument("CPF inválida!");
                }
                else{soma2 = soma2 + digito * peso;}
            }else{
                digito = cpf[i] - '0';
                soma1 = soma1 + (digito * (peso + 1));
                soma2 = soma2 + digito * peso;
                peso = peso + 1;
}}}}

void CPF::setCPF(string valor){
    validar(valor);
    this->valor = valor;
}

