#include <iostream>

#include "domains.h"

using namespace std;

void Dinheiro::validar(double valor){
    if (valor < 0 || valor > LIMITE)
        throw invalid_argument("Argumento invalido.");
}

void Dinheiro::setValor(double valor){
    validar(valor);
    this->valor = valor;
}

void Senha::validar(int senha){
    if (senha <= 100000 || senha > 999999)
        throw invalid_argument("Senha inválida! Não possui 6 dígitos.");

    string str = to_string(senha);

    if (str[0] == '0')
        throw invalid_argument("Senha inválida! O primeiro dígito não é diferente de zero.");
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j])
                throw invalid_argument("Senha inválida! Possui dígito duplicado.");
        }
    }
    bool isI = true, isD = true;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] >= str[i + 1])
            isI = false;
        if (str[i] <= str[i + 1])
            isD = false;
    }
    if (isI || isD)
        throw invalid_argument("Senha inválida! Possui dígitos sequenciais.");
}

void Senha::setValor(int valor){
    validar(valor);
    this->valor = valor;
}

//Methods - Codigo
void Codigo::setCodigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}

//Methods - Código Pagamento
void CodigoPagamento::validar(string codigo) const{

    if (codigo.size()!=8){throw length_error("Valor não está no tamanho de caracteres permitidos!");}

    int count = 0;
    for (char c : codigo)
    {
        if (!isdigit(c) or (count==0 && c=='0'))
        {
            throw invalid_argument("Valor inválido!");
        }
        count++;
    }
}

//Methods - Código Pagamento
void CodigoTitulo::validar (string codigo) const{
    string codCheck = codigo.substr(0, 3);
    bool verificador = true;
    auto it = find(listaTitulos.begin(), listaTitulos.end(), codCheck);

    if(!(codigo.size()
     ==  11)){ throw length_error("Valor do campo (CodigoTitulo) não está no tamanho permitido!");}

     else if(it == listaTitulos.end()) {
        throw invalid_argument("Valor inválido! Código Titulo invalido. Lista válidos: CDB , CRA, CRI, LCA, LCI e DEB.");
    }

    else{
        for (char c : codigo)
    {
        if (isupper(c)){
            verificador = true;
        }

        else if (isdigit(c)){
            verificador = true;
        }
        else{
            throw invalid_argument("Valor inválido! Contém letras minusculas ou simbólo.");
        }
    }
    }
}

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
