#include "ctrl_servico.h"
#include "comandos.h"
#include "containers.h"

using namespace std;

// Implementações de métodos de classe controladora de serviço para Títulos.
bool CntrISInvestimento::criar(const Titulo& titulo) {
    ContainerTitulos *container = ContainerTitulos::getInstancia();
    return container->incluir(titulo);
}

bool CntrISInvestimento::ler(Titulo* titulo) {
    ContainerTitulos *container = ContainerTitulos::getInstancia();
    return container->pesquisar(titulo);
}

bool CntrISInvestimento::atualizar(const Titulo& titulo) {
    ContainerTitulos *container = ContainerTitulos::getInstancia();
    return container->atualizar(titulo);
}

bool CntrISInvestimento::excluir(const CodigoTitulo& codigo) {
    ContainerTitulos *container = ContainerTitulos::getInstancia();
    return container->remover(codigo);
}

// Implementações de métodos de classe controladora de serviço para Pagamentos.
bool CntrISInvestimento::criar(const Pagamento& pagamento) {
    ContainerPagamentos *container = ContainerPagamentos::getInstancia();
    return container->incluir(pagamento);
}

bool CntrISInvestimento::ler(Pagamento* pagamento) {
    ContainerPagamentos *container = ContainerPagamentos::getInstancia();
    return container->pesquisar(pagamento);
}

bool CntrISInvestimento::atualizar(const Pagamento& pagamento) {
    ContainerPagamentos *container = ContainerPagamentos::getInstancia();
    return container->atualizar(pagamento);
}

bool CntrISInvestimento::excluir(const CodigoPagamento& codigo) {
    ContainerPagamentos *container = ContainerPagamentos::getInstancia();
    return container->remover(codigo);
}

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
