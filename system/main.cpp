#include <stdexcept>
#include <iostream>
#include <string>

#include "../library/domains.h"
#include "../library/entities.h"
#include "interfaces.h"
#include "ctrl_apresentacao.h"
#include "ctrl_servico.h"
#include "stubs.h"

using namespace std;

class ApresentacaoConta : public IAConta{
private:
    ISConta* cntrISConta;
public:
    void criar() override{
        Conta conta;

        CPF cpf;
        cpf.setCPF("123.456.789-00");
        conta.setNumCPF(cpf);

        bool sucesso = cntrISConta->criar(conta);

        if (sucesso){
            cout << "Conta criada com sucesso!" << endl;
        } else{
            cout << "Falha na criação da conta" << endl;
        }
    }

    int executar(const CPF& cpf) override{
        cout << "Executando ações para o CPF: " << cpf.getCPF() << endl;
        return 0;
    }

    void setCntrISConta(ISConta* cntr) override{
        cntrISConta = cntr;
    }
};

int main(){
    StubISConta stubServicoConta;
    ApresentacaoConta apresentacaoConta;

    apresentacaoConta.setCntrISConta(&stubServicoConta);

    apresentacaoConta.criar();

    return 0;
}
