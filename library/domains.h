
//bibliotecas
#include <iostream>

//macros
using namespace std; 
#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#endif // DOMAINS_H_INCLUDED


//Dominio - Codigo: Pagamento e Titulo
class Codigo{
    private:
        string codigo;
        virtual void validar(string codigo) const = 0;
    public:
        void setCodigo(string);
        inline string getCodigo(){return codigo;};
};

// Declaração: Código Titulo: Parra 211020956
// class CodigoTitulo : public Codigo{
//     private:
//         void validar(string) override;
// };

//Delcaração: Código Pagamento: Parra 211020956
class CodigoPagamento : public Codigo{
    private:
        void validar(string) const override;
};


class CodigoTitulo : public Codigo{
    protected:
        void validar(string) const override;
};
