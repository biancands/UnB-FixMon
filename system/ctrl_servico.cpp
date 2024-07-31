#include "ctrl_servico.h"
#include "comandos.h"

using namespace std;

bool cntrISConta::criar(const Conta& conta) {

    for(const auto& c : contas) {
        if(c.getNumCPF().getCPF() == conta.getNumCPF().getCPF()) {

            cout << "Error: CPF ja existe no Banco de Dados" << endl;
            return false;
        }
    }

    contas.push_back(conta);
    cout << "Sucesso: Conta criada!" << endl;
    return true;
}

bool cntrISConta::ler(Conta* conta){

    for(const auto& c : contas){
        if(c.getNumCPF().getCPF() == conta->getNumCPF().getCPF()){
            *conta = c;
            cout << "Sucesso: Dados da conta lidos com sucesso" << endl;
            return true;
        }
    }

    cout << "Error: Conta não encontrada" << endl;
    return false;
}


bool cntrISConta::atualizar(const Conta& conta) {

    for(auto& c : contas){

        if(c.getNumCPF().getCPF() == conta->getNumCPF().getCPF()){
            c = conta;
            cout << "Sucesso: Conta atualizada com sucesso!" << endl;
            return true;
        }
    }

    cout << "Error: Conta nao encontrada" << endl;
    return false;
}

bool cntrISConta::excluir(const CPF& cpf){
    auto it = remove_if(contas.begin(), contas.end(), [&](const Conta& c) {
        return c.getNumCPF().getCPF() == cpf.getCPF();
    });

    if (it != contas.end()) {
        contas.erase(it, contas.end());
        cout << "Conta excluída com sucesso!" << endl;
        return true;
    }
    cout << "Erro: Conta não encontrada." << endl;
    return false;
}