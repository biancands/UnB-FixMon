#include "domains.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

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







