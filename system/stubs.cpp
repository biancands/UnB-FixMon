#include "stubs.h"

using namespace std;
bool StubISConta::criar(const Conta& conta){
    cout << "StubISConta: criar chamado" << endl;
    return true;
}
bool StubISConta::ler(Conta* conta){
    cout << "StubISConta: ler chamado." << endl;
    return true;
};
bool StubISConta::atualizar(const Conta& conta){
    cout << "StubISConta: atualizar chamado." << endl;
    return true;
}
bool StubISConta::excluir(const CPF& cpf){
    cout << "StubISConta: excluir chamado." << endl;
    return true;
}
