#include "domains.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void Estado::setEstado(string estado){
    if(validar(estado)){
        this->estado=estado;
    }else{throw invalid_argument("Valor inválido!");}
}

bool Estado::validar(string estado){
    if(estado == "Previsto" || estado == "Liquidado" || estado == "Inadimplente"){
        return true;
    }else{return false;}
}

void CPF::setCPF(string cpf){
    if(validar(cpf)){
        this->cpf=cpf;
    }else{throw invalid_argument("Valor inválido!");}
}

bool CPF::validar(string cpf){
    int digito;
    int resto;
    int soma1 = 0;
    int soma2 = 0;
    int peso = 0;
    if(cpf.size() != 14){return false;}
    if(cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){return false;}
    for (int i = 0; i < 14; i++){
        if(i == 3 || i == 7 || i == 11){continue;}
        else{
            if(!isdigit(cpf[i])){return false;}
            else if(i == 13){
                digito = cpf[i] - '0';
                resto = soma2 % 11;
                if(resto == 10){resto = 0;}
                if(resto != digito){return false;}
                else{return true;}
            }else if(i == 12){
                digito = cpf[i] - '0';
                resto = soma1 % 11;
                if(resto == 10){resto = 0;}
                if(resto != digito){return false;}
                else{soma2 = soma2 + digito * peso;}
            }else{
                digito = cpf[i] - '0';
                soma1 = soma1 + (digito * (peso + 1));
                soma2 = soma2 + digito * peso;
                peso = peso + 1;
}}}}

main(){

    return 0;
}
