#include "stubs.h"

using namespace std;

bool StubISAutenticacao::autenticar(const string &cpf, const string &senha) {
    cout << endl << "StubISAutenticacao::autenticar" << endl;
    cout << "CPF   = " << cpf << endl;
    cout << "Senha = " << senha << endl;

    bool resultado = true;

    if (cpf == to_string(TRIGGER_FALHA)) {
        resultado = false;
    } else if (cpf == to_string(TRIGGER_ERRO_SISTEMA)) {
        throw runtime_error("Erro de sistema");
    }

    return resultado;
}
