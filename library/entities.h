#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

#include "domains.h"

#include <string>

using namespace std;

//231013583
class Titulo {
private:
    CodigoTitulo codigo;
    Nome emissor;
    Setor setor;
    Data emissao;
    Data vencimento;
    Dinheiro valor;
public:
    void setCodigo(const CodigoTitulo&);
    CodigoTitulo getCodigo() const;
    void setEmissor(const Nome&);
    Nome getEmissor() const;
    void setSetor(const Setor&);
    Setor getSetor() const;
    void setEmissao(const Data&);
    Data getEmissao() const;
    void setVencimento(const Data&);
    Data getVencimento() const;
    void setValor(const Dinheiro&);
    Dinheiro getValor() const;
};

inline void Titulo::setCodigo(const CodigoTitulo& codigo){
    this->codigo = codigo;
}

inline CodigoTitulo Titulo::getCodigo() const {
    return codigo;
}

inline void Titulo::setEmissor(const Nome& emissor){
    this->emissor = emissor;
}

inline Nome Titulo::getEmissor() const {
    return emissor;
}

inline void Titulo::setSetor(const Setor& setor){
    this->setor = setor;
}

inline Setor Titulo::getSetor() const {
    return setor;
}

inline void Titulo::setEmissao(const Data& emissao){
    this->emissao = emissao;
}

inline Data Titulo::getEmissao() const {
    return emissao;
}

inline void Titulo::setVencimento(const Data& vencimento){
    this->vencimento = vencimento;
}

inline Data Titulo::getVencimento() const {
    return vencimento;
}

inline void Titulo::setValor(const Dinheiro& valor){
    this->valor = valor;
}

inline Dinheiro Titulo::getValor() const {
    return valor;
}

#endif // ENTITIES_H_INCLUDED
