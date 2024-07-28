#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

class StubISAutenticacao : public ISAutenticacao {
public:
    const static int TRIGGER_FALHA = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    bool autenticar(const string&, const string&);
};

#endif // STUBS_H_INCLUDED
