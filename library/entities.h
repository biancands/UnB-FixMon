#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

#include "domains.h"
#include <string>

using namespace std;

//200040979
class Conta {
private:
    CPF cpf;
    Nome nome_um;
    Nome nome_dois;
    Senha senha;

public:
    Conta() : nome_um("Nome", "Valido"), nome_dois("Nome", "Valido") {}

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

//222014142
class Pagamento {
private:
    CodigoPagamento codigo;
    Data data;
    Percentual percentual;
    Estado estado;
public:
    void setCodigo(const CodigoPagamento&);
    CodigoPagamento getCodigo() const;
    void setData(const Data&);
    Data getData() const;
    void setPercentual(const Percentual&);
    Percentual getPercentual() const;
    void setEstado(const Estado&);
    Estado getEstado() const;
};

inline void Pagamento::setCodigo(const CodigoPagamento& codigo){
    this->codigo = codigo;
}

inline CodigoPagamento Pagamento::getCodigo() const {
    return codigo;
}

inline void Pagamento::setData(const Data& data){
    this->data = data;
}

inline Data Pagamento::getData() const {
    return data;
}

inline void Pagamento::setPercentual(const Percentual& percentual){
    this->percentual = percentual;
}

inline Percentual Pagamento::getPercentual() const {
    return percentual;
}

inline void Pagamento::setEstado(const Estado& estado){
    this->estado = estado;
}

inline Estado Pagamento::getEstado() const {
    return estado;
}

#endif
