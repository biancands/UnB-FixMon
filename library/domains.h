//bibliotecas
#include <iostream>
#include <algorithm>

//macros
using namespace std;
#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#endif // DOMAINS_H_INCLUDED

//Class Estado por Danilo Silveira da Silva - 222014142
class Estado {
private:
    string estado;
    virtual bool validar(string estado);
public:
    void setEstado(string);
    inline string getEstado(){return estado;};
};

//Class CPF por Danilo Silveira da Silva - 222014142
class CPF{
private:
    string cpf;
    virtual bool validar(string cpf);
public:
    void setCPF(string);
    inline string getCPF(){return cpf;};
};
