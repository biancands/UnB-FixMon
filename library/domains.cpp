#include "domains.h"
using namespace std;
#include <iostream>


//Declaração metodos Codigo:
void Codigo::setCodigo(string codigo){   
    validar(codigo);
    this->codigo=codigo;
}

//Code Methods: Código Pagamento - Parra 211020956
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

void CodigoTitulo::validar (string codigo) const{
    string codCheck = codigo.substr(0, 3);
    bool verificador = true;
    auto it = find(listaTitulos.begin(), listaTitulos.end(), codCheck);

    //Primeira verificação: Tamanho do código, tem que ser 11 de acordo com as regras de negócios.
    if(!(codigo.size()
     ==  11)){ throw length_error("Valor do campo (CodigoTitulo) não está no tamanho permitido!");} 

    //Segunda verificação: 3 primeiras letras tem que está dentro da listaTitulos.
     else if(it == listaTitulos.end()) {
        throw invalid_argument("Valor inválido! Código Titulo invalido. Lista válidos: CDB , CRA, CRI, LCA, LCI e DEB.");
    }

    //Terceira validação: Valores no lugar de x tem que ser letras maísuculas e 0-9. 
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
            throw invalid_argument("Valor inválido! Contém letras minusculas ou algum simbólo.");
        }
    }
    }
}
