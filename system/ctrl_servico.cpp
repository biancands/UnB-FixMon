#include "ctrl_servico.h"
#include "comandos.h"
#include "containers.h"

using namespace std;

// Implementa��es de m�todos de classe controladora de servi�o para T�tulos.
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

// Implementa��es de m�todos de classe controladora de servi�o para Pagamentos.
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
