#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

#include "domains.h"
#include <string>

using namespace std;

class Conta {
private:
    CPF cpf;
    Nome nome_um;
    Nome nome_dois;
    Senha senha;

public:
    Conta() : nome_um("Nome", "Valido"), nome_dois("Nome", "Valido") {}  // Construtor padrão atualizado com valores válidos

    void setNumCPF(const CPF&);
    CPF getNumCPF() const;

    void setNomeUm(const Nome&);
    Nome getNomeUm() const;

    void setNomeDois(const Nome&);
    Nome getNomeDois() const;

    void setSenha(const Senha&);
    Senha getSenha() const;
};

inline void Conta::setSenha(const Senha& senha) {
    this->senha = senha;
}

inline Senha Conta::getSenha() const {
    return senha;
}

inline void Conta::setNumCPF(const CPF& cpf) {
    this->cpf = cpf;
}

inline CPF Conta::getNumCPF() const {
    return cpf;
}

inline void Conta::setNomeUm(const Nome& nome_um) {
    this->nome_um = nome_um;
}

inline Nome Conta::getNomeUm() const {
    return nome_um;
}

inline void Conta::setNomeDois(const Nome& nome_dois) {
    this->nome_dois = nome_dois;
}

inline Nome Conta::getNomeDois() const {
    return nome_dois;
}

#endif
