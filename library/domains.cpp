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
    int count = 0;
    for (char c : codigo)
    {
        if (!isdigit(c) or (count==0 && c=='0'))
        {
            throw invalid_argument("Valor inválido!");
        }
        count++;
    }

    if (count != 8){throw invalid_argument("Valor utrapassou o limite de caracteres!");}
}


void CodigoTitulo::validar (string codigo) const{

    int count = 0;
    string codCheck;

    for (char c : codigo)
    {
        if (count == 11 or !isdigit(c)){throw invalid_argument("Valor não está de acordo com as regras de negocio!");}
        count++;
        codCheck += c;
    }

}


//Teste
// int main(){
//      string t;
//      cin >> t;
//      CodigoPagamento teste;
//      teste.setCodigo(t);

//      cout << teste.getCodigo() << endl;

//      teste.setCodigo("23456789");
//      cout << teste.getCodigo() << endl;

//      }
