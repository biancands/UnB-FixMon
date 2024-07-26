#include "ctrl_apresentacao.h"
#include "comandos.h"

using namespace std;
void CntrIAConta::setCntrISConta(ISConta* cntrISConta){
    this -> cntrISConta = cntrISConta;
}
bool CntrIAConta::criar(Conta* conta){
    return cntrISConta ->criar(conta);
}

bool CntrIAConta::ler(Conta* conta){
    return cntrISConta -> ler(conta);
}

bool CntrIAConta::atualizar(Conta* conta){
    return cntrISConta -> atualizar(conta);
}

bool CntrIAConta::excluir(CPF* cpf){
    return cntrISConta -> excluir(cpf);
}