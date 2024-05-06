#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

#include "domains.h"

#include <string>

using namespace std;

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


#endif // ENTITIES_H_INCLUDED
