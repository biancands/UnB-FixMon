#include <stdexcept>
#include <iostream>
#include <string>

#include "domains.h"
#include "entities.h"
#include "interfaces.h"
#include "ctrl_apresentacao.h"
#include "ctrl_servico.h"

using namespace std;

int main() {
    IAAutenticacao *cntrIAAutenticacao = new CntrIAAutenticacao();
    ISAutenticacao *cntrISAutenticacao = new CntrServicoAutenticacao();
    cntrIAAutenticacao->setCntrISAutenticacao(cntrISAutenticacao);

    IAConta *cntrIAConta = new CntrIAConta();
    ISConta *cntrISConta = new CntrServicoConta();
    cntrIAConta->setCntrISConta(cntrISConta);

    bool resultado;
    CPF cpf;
    Senha senha;

    while (true) {
        cout << endl << "Tela inicial do sistema." << endl;
        cout << "1. Autenticar" << endl;
        cout << "2. Criar Conta" << endl;
        cout << "3. Sair" << endl;
        cout << "Selecione uma opcao: ";

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                resultado = cntrIAAutenticacao->autenticar(&cpf, &senha);
                if (resultado) {
                    cout << endl << "Autenticado!" << endl;
                    cout << "1. Contas" << endl;
                    cout << "2. Titulos" << endl;
                    cout << "3. Pagamentos" << endl;
                    cout << "4. Sair" << endl;
                    cout << "Selecione uma opcao: ";

                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            cntrIAConta->executar(cpf);
                            break;
                        case 2:
                            cout << "Funcionalidade de Titulos não implementada." << endl;
                            break;
                        case 3:
                            cout << "Funcionalidade de Pagamentos não implementada." << endl;
                            break;
                        case 4:
                            cout << "Saindo." << endl;
                            delete cntrIAAutenticacao;
                            delete cntrISAutenticacao;
                            delete cntrIAConta;
                            delete cntrISConta;
                            return 0;
                        default:
                            cout << "Opção inválida." << endl;
                            break;
                    }
                } else {
                    cout << "Falha na autenticação." << endl;
                }
                break;

            case 2:
                cntrIAConta->criar();
                break;

            case 3:
                cout << "Saindo" << endl;
                delete cntrIAAutenticacao;
                delete cntrISAutenticacao;
                delete cntrIAConta;
                delete cntrISConta;
                return 0;

            default:
                cout << "Opção inválida." << endl;
                break;
        }
    }

    delete cntrIAAutenticacao;
    delete cntrISAutenticacao;
    delete cntrIAConta;
    delete cntrISConta;

    return 0;
}
