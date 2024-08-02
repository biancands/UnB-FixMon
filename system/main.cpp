#include <stdexcept>
#include <iostream>
#include <string>

#include "domains.h"
#include "entities.h"
#include "interfaces.h"
#include "ctrl_apresentacao.h"
#include "ctrl_servico.h"
#include "stubs.h"
#include "containers.h"

using namespace std;

int main() {
    IAAutenticacao *cntrIAAutenticacao;
    cntrIAAutenticacao = new CntrIAAutenticacao();

    ISAutenticacao *stubISAutenticacao;
    stubISAutenticacao = new StubISAutenticacao();

    cntrIAAutenticacao->setCntrISAutenticacao(stubISAutenticacao);

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
                    cout << endl << "#######################################################################################################################" << endl;
                    cout << "1. Contas" << endl;
                    cout << "2. Titulos" << endl;
                    cout << "3. Pagamentos" << endl;
                    cout << "4. Sair" << endl;
                    cout << "Selecione uma opcao: ";

                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            cout << endl << "Aqui vai a parte de contas!" << endl;
                            break;

                        case 2: {
                            CntrIAInvestimento *cntrIAInvestimento = new CntrIAInvestimento();
                            ISInvestimento *cntrISInvestimento = new CntrISInvestimento();
                            cntrIAInvestimento->setCntrISInvestimento(cntrISInvestimento);

                            cntrIAInvestimento->executar(cpf);

                            delete cntrIAInvestimento;
                            delete cntrISInvestimento;
                            break;
                        }

                        case 3:
                            cout << endl << "Aqui vai a parte de Pagamentos!" << endl;
                            break;

                        case 4:
                            cout << endl << "SAINDO!" << endl;
                            return 0;

                        default:
                            cout << "Opcao invalida!" << endl;
                            break;
                    }
                } else {
                    cout << endl << "Falha na autenticacao." << endl;
                }
                break;

            case 2:
                cout << "Aqui vai a parte de criar conta!" << endl;
                break;

            case 3:
                cout << "Saindo" << endl;
                return 0;

            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }

    delete cntrIAAutenticacao;
    delete stubISAutenticacao;

    return 0;
}
