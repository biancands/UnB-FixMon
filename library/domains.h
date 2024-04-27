#ifndef DOMAINS_H
#define DOMAINS_H

#include <string>

class Data {
private:
    int dia, mes, ano;
    bool ehBissexto(int);
    void validarDia(int, int);
    void validarMes(int);
    void validarAno(int);
    void validarFormatoData(const std::string&);
public:
    Data();
    Data(const std::string&);
    void validarData(const std::string&);


    void setDia(int, int);
    void setMes(int);
    void setAno(int);

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

