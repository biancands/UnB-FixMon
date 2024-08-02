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

// Implementações do StubISInvestimento
bool StubISInvestimento::criar(const Titulo& titulo) {
    cout << "StubISInvestimento::criar - Titulo criado com sucesso" << endl;
    return true;
}

bool StubISInvestimento::ler(Titulo* titulo) {
    cout << "StubISInvestimento::ler - Leitura do titulo realizada com sucesso" << endl;
    return true;
}

bool StubISInvestimento::atualizar(const Titulo& titulo) {
    cout << "StubISInvestimento::atualizar - Titulo atualizado com sucesso" << endl;
    return true;
}

bool StubISInvestimento::excluir(const CodigoTitulo& codigo) {
    cout << "StubISInvestimento::excluir - Titulo excluido com sucesso" << endl;
    return true;
}

bool StubISInvestimento::criar(const Pagamento& pagamento) {
    cout << "StubISInvestimento::criar - Pagamento criado com sucesso" << endl;
    return true;
}

bool StubISInvestimento::ler(Pagamento* pagamento) {
    cout << "StubISInvestimento::ler - Leitura do pagamento realizada com sucesso" << endl;
    return true;
}

bool StubISInvestimento::atualizar(const Pagamento& pagamento) {
    cout << "StubISInvestimento::atualizar - Pagamento atualizado com sucesso" << endl;
    return true;
}

bool StubISInvestimento::excluir(const CodigoPagamento& codigo) {
    cout << "StubISInvestimento::excluir - Pagamento excluido com sucesso" << endl;
    return true;
}
