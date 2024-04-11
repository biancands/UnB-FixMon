
//bibliotecas
#include <iostream>

//macros
using namespace std; 

#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED



#endif // DOMAINS_H_INCLUDED

// Class Código Titulo - Parra 211020956

//Dominio
class CodigoTitulo{

    private:
        string codigo;
        bool validar(string);
    public:

        void setCodigo(string);
        string getCodigo();
};

inline string CodigoTitulo::getCodigo(){
    return codigo;
}

// Declaração herdadas de Codigo Titulo:

class CDB : public CodigoTitulo{
    private:
        bool validar(string); 
};

class CRA : public CodigoTitulo{
    private:
        bool validar(string); 
};

class CRI : public CodigoTitulo{
    private:
        bool validar(string); 
};

class LCA : public CodigoTitulo{
    private:
        bool validar(string); 
};

class LCI : public CodigoTitulo{
    private:
        bool validar(string); 
};

class DEB : public CodigoTitulo{
    private:
        bool validar(string); 
};