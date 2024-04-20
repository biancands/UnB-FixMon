#include "domains.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

Data::Data() : dia(0), mes(0), ano(0) {}

Data::Data(const std::string& data) {
    setData(data);
}

void Data::setData(const std::string& data) {
    std::stringstream ss(data);
    char delim;
    ss >> dia >> delim >> mes >> delim >> ano;
    if (ss.fail() || ss.peek() != EOF) {
        throw std::length_error("Erro: Formato de data invalido");
        exit(1);
        }

    validarDia(dia, mes);
    validarMes(mes);
    validarAno(ano);
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
    if (d < 1 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) || (m == 2 && ((ehBissexto(ano) && d > 29) || (!ehBissexto(ano) && d > 28))) || (m != 2 && d > 31)) {
        throw std::invalid_argument("Erro: Dia invalido");
        exit(1);
    }
}

void Data::validarMes(int m) {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Erro: Mes invalido");
        exit(1);
    }
}

void Data::validarAno(int a) {
    if (a < 2000 || a > 2100) {
        throw std::length_error("Erro: Ano invalido");
        exit(1);
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
        throw std::length_error("Erro: Valor invalido");
        exit(1);
    }
}







