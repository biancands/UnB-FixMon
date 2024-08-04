#include "containers.h"

// Inicialização das instâncias Singleton.
ContainerTitulos* ContainerTitulos::instancia = nullptr;
ContainerPagamentos* ContainerPagamentos::instancia = nullptr;

// Implementações de métodos de classe container para Títulos.

ContainerTitulos* ContainerTitulos::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerTitulos();
    return instancia;
}

bool ContainerTitulos::incluir(Titulo titulo){
    return container.insert(make_pair(titulo.getCodigo().getCodigo(), titulo)).second;
}

bool ContainerTitulos::remover(CodigoTitulo codigo){
    map<string, Titulo>::iterator it = container.find(codigo.getCodigo());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerTitulos::pesquisar(Titulo* titulo){
    map<string, Titulo>::iterator it = container.find(titulo->getCodigo().getCodigo());
    if(it != container.end()){
        *titulo = it->second;
        return true;
    }
    return false;
}

bool ContainerTitulos::atualizar(Titulo titulo){
    map<string, Titulo>::iterator it = container.find(titulo.getCodigo().getCodigo());
    if(it != container.end()){
        it->second = titulo;
        return true;
    }
    return false;
}

// Implementações de métodos de classe container para Pagamentos.

ContainerPagamentos* ContainerPagamentos::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerPagamentos();
    return instancia;
}

bool ContainerPagamentos::incluir(Pagamento pagamento){
    return container.insert(make_pair(pagamento.getCodigo().getCodigo(), pagamento)).second;
}

bool ContainerPagamentos::remover(CodigoPagamento codigo){
    map<string, Pagamento>::iterator it = container.find(codigo.getCodigo());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerPagamentos::pesquisar(Pagamento* pagamento){
    map<string, Pagamento>::iterator it = container.find(pagamento->getCodigo().getCodigo());
    if(it != container.end()){
        *pagamento = it->second;
        return true;
    }
    return false;
}

bool ContainerPagamentos::atualizar(Pagamento pagamento){
    map<string, Pagamento>::iterator it = container.find(pagamento.getCodigo().getCodigo());
    if(it != container.end()){
        it->second = pagamento;
        return true;
    }
    return false;
}

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
