#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#include <stdexcept>
#include <string>

using namespace std;

//222014142
class Estado{
private:
    string valor;
    void validar(string);
public:
    void setEstado(string);
    string getEstado() const;
};

inline string Estado::getEstado() const{
    return valor;
}

//222014142
class CPF{
private:
    string valor;
    void validar(string);
public:
    void setCPF(string);
    string getCPF() const;
};

inline string CPF::getCPF() const{
    return valor;
}

#endif // DOMAINS_H_INCLUDED
