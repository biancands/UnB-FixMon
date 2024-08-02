#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

class StubISConta:public ISConta{
public:

    //Gatilhos de notificação
    const static int TRIGGER_FALHA        =  10000 ;
    const static int TRIGGER_ERRO_SISTEMA = 20000 ;

    //Declaração de metodos da interface.
    bool criar(const Conta&) override;
    bool ler(Conta*) override;
    bool atualizar(const Conta&) override;
    bool excluir(const CPF&) override;

};
#endif // STUBS_H_INCLUDED
