#ifndef CTRL_SERVICO_H_INCLUDED
#define CTRL_SERVICO_H_INCLUDED

#include "interfaces.h"
#include "domains.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class cntrISConta: public ISConta{

    private:
        vector<Conta> contas;  //banco improvisado simulando contas
    public:
        bool criar(const Conta&);
        bool ler(Conta*);
        bool atualizar(const Conta&);
        bool excluir(const CPF&);   
};

#endif // CTRL_SERVICO_H_INCLUDED
