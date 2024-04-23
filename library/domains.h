#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#include <iostream>
#include <algorithm>

using namespace std;

//Parra - 211020956
class Codigo{
    private:
        string codigo;
        virtual void validar(string codigo) const = 0;
    public:
        void setCodigo(string);
        inline string getCodigo(){return codigo;}
};

//Parra - 211020956
class CodigoPagamento : public Codigo{
    private:
        void validar(string) const override;
};


//Parra - 211020956
class CodigoTitulo : public Codigo{
    protected:
        void validar(string) const override;
    public:
        const vector<string> listaTitulos = {"CDB","CRA","CRI",
"LCA","LCI","DEB"};
};

#endif // DOMAINS_H_INCLUDED


