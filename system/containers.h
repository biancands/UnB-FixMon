#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "../library/entities.h"
#include <map>

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
