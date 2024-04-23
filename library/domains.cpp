#include <iostream>

#include "domains.h"

using namespace std;

//Methods - Codigo
void Codigo::setCodigo(string codigo){   
    validar(codigo);
    this->codigo=codigo;
}

//Methods - Código Pagamento
void CodigoPagamento::validar(string codigo) const{

    if (codigo.size()!=8){throw length_error("Valor não está no tamanho de caracteres permitidos!");}

    int count = 0;
    for (char c : codigo)
    {
        if (!isdigit(c) or (count==0 && c=='0'))
        {
            throw invalid_argument("Valor inválido!");
        }
        count++;
    }
}

//Methods - Código Pagamento
void CodigoTitulo::validar (string codigo) const{
    string codCheck = codigo.substr(0, 3);
    bool verificador = true;
    auto it = find(listaTitulos.begin(), listaTitulos.end(), codCheck);

    if(!(codigo.size()
     ==  11)){ throw length_error("Valor do campo (CodigoTitulo) não está no tamanho permitido!");} 

     else if(it == listaTitulos.end()) {
        throw invalid_argument("Valor inválido! Código Titulo invalido. Lista válidos: CDB , CRA, CRI, LCA, LCI e DEB.");
    }

    else{
        for (char c : codigo)
    {
        if (isupper(c)){
            verificador = true;
        }
        
        else if (isdigit(c)){
            verificador = true;
        }
        else{
            throw invalid_argument("Valor inválido! Contém letras minusculas ou simbólo.");
        }
    }
    }
}
