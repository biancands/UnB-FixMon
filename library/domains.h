#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#include <stdexcept>
#include <string>

using namespace std;

//231013583
class Dinheiro {
private:
    static constexpr double LIMITE = 1000000.00;
    double valor;
    void validar(double);
public:
    void setValor(double);
    double getValor() const;
};

inline double Dinheiro::getValor() const{
    return valor;
}

//231013583
class Senha {
private:
    int valor;
    void validar(int);
public:
    void setValor(int);
    int getValor() const;
};

inline int Senha::getValor() const{
    return valor;
}

#endif // DOMAINS_H_INCLUDED
