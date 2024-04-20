#ifndef DOMAINS_H
#define DOMAINS_H

#include <string>

class Data {
private:
    int dia, mes, ano;
    void validarDia(int, int);
    void validarMes(int);
    void validarAno(int);
    bool ehBissexto(int);

public:
    Data();
    Data(const std::string&);
    void setData(const std::string&);
    int getDia() const;
    int getMes() const;
    int getAno() const;
};



class Percentual {
private:
    int valor;
    void validarValor(int);
public:
    void setValor(int);
    int getValor() const;
};

#endif // DOMAINS_H

