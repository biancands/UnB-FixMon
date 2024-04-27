#include <iostream>
#include <sstream>

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
        throw invalid_argument("Senha inv�lida! N�o possui 6 d�gitos.");

    string str = to_string(senha);

    if (str[0] == '0')
        throw invalid_argument("Senha inv�lida! O primeiro d�gito n�o � diferente de zero.");
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j])
                throw invalid_argument("Senha inv�lida! Possui d�gito duplicado.");
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
        throw invalid_argument("Senha inv�lida! Possui d�gitos sequenciais.");
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

//Methods - C�digo Pagamento
void CodigoPagamento::validar(string codigo) const{

    if (codigo.size()!=8){throw length_error("Valor n�o est� no tamanho de caracteres permitidos!");}

    int count = 0;
    for (char c : codigo)
    {
        if (!isdigit(c) or (count==0 && c=='0'))
        {
            throw invalid_argument("Valor inv�lido!");
        }
        count++;
    }
}

//Methods - C�digo Pagamento
void CodigoTitulo::validar (string codigo) const{
    string codCheck = codigo.substr(0, 3);
    bool verificador = true;
    auto it = find(listaTitulos.begin(), listaTitulos.end(), codCheck);

    if(!(codigo.size()
     ==  11)){ throw length_error("Valor do campo (CodigoTitulo) n�o est� no tamanho permitido!");}

     else if(it == listaTitulos.end()) {
        throw invalid_argument("Valor inv�lido! C�digo Titulo invalido. Lista v�lidos: CDB , CRA, CRI, LCA, LCI e DEB.");
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
            throw invalid_argument("Valor inv�lido! Cont�m letras minusculas ou simb�lo.");
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
            throw invalid_argument("CPF inv�lida! N�o possui 14 carcteres.");
    }
    if(cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
            throw invalid_argument("CPF inv�lida! Pontua��o errada.");
    }
    for (int i = 0; i < 14; i++){
        if(i == 3 || i == 7 || i == 11){continue;}
        else{
            if(!isdigit(cpf[i])){
                throw invalid_argument("CPF inv�lida! N�o � digito.");
        }
            else if(i == 13){
                digito = cpf[i] - '0';
                resto = soma2 % 11;
                if(resto == 10){resto = 0;}
                if(resto != digito){
                        throw invalid_argument("CPF inv�lida!");
                }
            }else if(i == 12){
                digito = cpf[i] - '0';
                resto = soma1 % 11;
                if(resto == 10){resto = 0;}
                if(resto != digito){
                        throw invalid_argument("CPF inv�lida!");
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

Data::Data() : dia(0), mes(0), ano(0) {}

Data::Data(const std::string& data) {
    validarData(data);
}


void Data::setDia(int d, int m) {
    validarDia(d, m);
    dia = d;
}

void Data::setMes(int m) {
    validarMes(m);
    mes = m;
}

void Data::setAno(int a) {
    validarAno(a);
    ano = a;
}

int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAno() const {
    return ano;
}


void Data::validarDia(int d, int m) {
    if (d < 1 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) || (m == 2 && ((ehBissexto(ano) && d > 29) ||
                                                        (!ehBissexto(ano) && d > 28))) || (m != 2 && d > 31)) {
        throw std::invalid_argument("Erro: Dia invalido");
    }
}

void Data::validarMes(int m) {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Erro: Mes invalido");
    }
}

void Data::validarAno(int a) {
    if (a < 2000 || a > 2100) {
        throw std::invalid_argument("Erro: Ano invalido");
    }
}

void Data::validarFormatoData(const std::string& data){
    std::stringstream ss(data);
    char delim;
    ss >> dia >> delim >> mes >> delim >> ano;
    if (ss.fail() || ss.peek() != EOF) {
        throw std::invalid_argument("Erro: Formato de data invalido");
        }
}

void Data::validarData(const std::string& data) {
    try{
        validarFormatoData(data);
        validarDia(dia, mes);
        validarMes(mes);
        validarAno(ano);
    }
    catch (const std::invalid_argument& e) {
        dia = -1; mes = -1; ano = -1;
        throw std::invalid_argument("Erro: Data invalida");
    }
}

bool Data::ehBissexto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

//Definição de métodos percentual
void Percentual::setValor(int v) {
    validarValor(v);
    valor = v;
}

int Percentual::getValor() const {
    return valor;
    }

void Percentual::validarValor(int v){
    if(v < 0 || v > 100 ){
        throw std::invalid_argument("Erro: Valor invalido");
            }
}
