#include "ctrl_servico.h"
//200040979
bool CntrServicoAutenticacao::autenticar(const string &cpf, const string &senha) {
    ContainerConta *container;
    container = ContainerConta::getInstancia();

    Conta conta;
    CPF cpfObj;
    cpfObj.setCPF(cpf);
    conta.setNumCPF(cpfObj);
    if(container->pesquisar(&conta) && conta.getSenha().getValor() == senha) {
        return true;
    }
    return false;
}

bool CntrServicoConta::criar(const Conta &conta) {
    ContainerConta *container;
    container = ContainerConta::getInstancia();
    return container->incluir(conta);
}

bool CntrServicoConta::ler(Conta *conta) {
    ContainerConta *container;
    container = ContainerConta::getInstancia();
    return container->pesquisar(conta);
}

bool CntrServicoConta::atualizar(const Conta &conta) {
    ContainerConta *container;
    container = ContainerConta::getInstancia();
    return container->atualizar(conta);
}

bool CntrServicoConta::excluir(const CPF &cpf) {
    ContainerConta *container;
    container = ContainerConta::getInstancia();
    return container->remover(cpf);
}
