#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "domains.h"
#include "entities.h"

#include <map>

using namespace std;

//231013583
class ContainerTitulos {
private:
    map<string, Titulo> container;                    // Mapa de títulos.
    static ContainerTitulos *instancia;               // Ponteiro para instância da classe.
    ContainerTitulos(){};                             // Construtor.
public:
    static ContainerTitulos* getInstancia();          // Método para instanciar classe.
    bool incluir(Titulo);                             // Métodos responsáveis por prestar serviços.
    bool remover(CodigoTitulo);
    bool pesquisar(Titulo*);
    bool atualizar(Titulo);
};

//231013583
class ContainerPagamentos {
private:
    map<string, Pagamento> container;                 // Mapa de pagamentos.
    static ContainerPagamentos *instancia;            // Ponteiro para instância da classe.
    ContainerPagamentos(){};                          // Construtor.
public:
    static ContainerPagamentos* getInstancia();       // Método para instanciar classe.
    bool incluir(Pagamento);                          // Métodos responsáveis por prestar serviços.
    bool remover(CodigoPagamento);
    bool pesquisar(Pagamento*);
    bool atualizar(Pagamento);
};

class ContainerConta {
private:
    map<string, Conta> container;
    static ContainerConta *instancia;
    ContainerConta() {}
public:
    static ContainerConta* getInstancia();
    bool incluir(Conta);
    bool remover(CPF);
    bool pesquisar(Conta*);
    bool atualizar(Conta);
};


#endif // CONTAINERS_H_INCLUDED
