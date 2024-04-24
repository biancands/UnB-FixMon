#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

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


