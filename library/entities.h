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

// Implementações Inline da Classe Conta
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

inline void Conta::setSenha(const Senha& senha) {
    this->senha = senha;
}

inline Senha Conta::getSenha() const {
    return senha;
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

// Implementações Inline da Classe Pagamento
inline void Pagamento::setCodigo(const CodigoPagamento& codigo) {
    this->codigo = codigo;
}

inline CodigoPagamento Pagamento::getCodigo() const {
    return codigo;
}

inline void Pagamento::setData(const Data& data) {
    this->data = data;
}

inline Data Pagamento::getData() const {
    return data;
}

inline void Pagamento::setPercentual(const Percentual& percentual) {
    this->percentual = percentual;
}

inline Percentual Pagamento::getPercentual() const {
    return percentual;
}

inline void Pagamento::setEstado(const Estado& estado) {
    this->estado = estado;
}

inline Estado Pagamento::getEstado() const {
    return estado;
}

//231013583
class Titulo {
private:
    CodigoTitulo codigo;
    Nome emissor_um;
    Nome emissor_dois;
    Setor setor;
    Data emissao;
    Data vencimento;
    Dinheiro valor;

public:
    Titulo() : emissor_um("Nome", "Valido"), emissor_dois("Nome", "Valido"), setor("Agricultura") {}

    void setCodigo(const CodigoTitulo&);
    CodigoTitulo getCodigo() const;

    void setEmissorUm(const Nome&);
    Nome getEmissorUm() const;

    void setEmissorDois(const Nome&);
    Nome getEmissorDois() const;

    void setSetor(const Setor&);
    Setor getSetor() const;

    void setEmissao(const Data&);
    Data getEmissao() const;

    void setVencimento(const Data&);
    Data getVencimento() const;

    void setValor(const Dinheiro&);
    Dinheiro getValor() const;
};

// Implementações Inline da Classe Titulo
inline void Titulo::setCodigo(const CodigoTitulo& codigo) {
    this->codigo = codigo;
}

inline CodigoTitulo Titulo::getCodigo() const {
    return codigo;
}

inline void Titulo::setEmissorUm(const Nome& emissor_um) {
    this->emissor_um = emissor_um;
}

inline Nome Titulo::getEmissorUm() const {
    return emissor_um;
}

inline void Titulo::setEmissorDois(const Nome& emissor_dois) {
    this->emissor_dois = emissor_dois;
}

inline Nome Titulo::getEmissorDois() const {
    return emissor_dois;
}

inline void Titulo::setSetor(const Setor& setor) {
    this->setor = setor;
}

inline Setor Titulo::getSetor() const {
    return setor;
}

inline void Titulo::setEmissao(const Data& emissao) {
    this->emissao = emissao;
}

inline Data Titulo::getEmissao() const {
    return emissao;
}

inline void Titulo::setVencimento(const Data& vencimento) {
    this->vencimento = vencimento;
}

inline Data Titulo::getVencimento() const {
    return vencimento;
}

inline void Titulo::setValor(const Dinheiro& valor) {
    this->valor = valor;
}

inline Dinheiro Titulo::getValor() const {
    return valor;
}

#endif // ENTITIES_H_INCLUDED
