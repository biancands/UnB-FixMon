#include "containers.h"

ContainerConta* ContainerConta::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerConta();
    }
    return instancia;
}

bool ContainerConta::incluir(Conta conta) {
    return container.insert(make_pair(conta.getNumCPF().getCPF(), conta)).second;
}

bool ContainerConta::remover(CPF cpf) {
    auto it = container.find(cpf.getCPF());
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerConta::pesquisar(Conta *conta) {
    auto it = container.find(conta->getNumCPF().getCPF());
    if (it != container.end()) {
        *conta = it->second;
        return true;
    }
    return false;
}

bool ContainerConta::atualizar(Conta conta) {
    auto it = container.find(conta.getNumCPF().getCPF());
    if (it != container.end()) {
        it->second = conta;
        return true;
    }
    return false;
}
