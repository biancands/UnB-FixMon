#include "domains.h"

using namespace std;

void Dinheiro::validar(double valor){
    if (valor < 0 || valor > LIMITE)
        throw invalid_argument("Argumento invalido.");
}

void Dinheiro::setValor(double valor){
    validar(valor);
    this->valor = valor;
}

void Senha::validar(int senha){
    if (senha <= 100000 || senha > 999999)
        throw invalid_argument("Senha inválida! Não possui 6 dígitos.");

    string str = to_string(senha);

    if (str[0] == '0')
        throw invalid_argument("Senha inválida! O primeiro dígito não é diferente de zero.");
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j])
                throw invalid_argument("Senha inválida! Possui dígito duplicado.");
        }
    }
    bool isI = true, isD = true;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] >= str[i + 1])
            isI = false;
        if (str[i] <= str[i + 1])
            isD = false;
    }
    if (isI || isD)
        throw invalid_argument("Senha inválida! Possui dígitos sequenciais.");
}

void Senha::setValor(int valor){
    validar(valor);
    this->valor = valor;
}
