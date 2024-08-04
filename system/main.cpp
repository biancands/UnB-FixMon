#include <stdexcept>
#include <iostream>
#include <string>

#include "domains.h"
#include "entities.h"
#include "interfaces.h"
#include "ctrl_apresentacao.h"
#include "ctrl_servico.h"
#include "containers.h"

using namespace std;

// Função principal
int main() {
    IAAutenticacao *cntrIAAutenticacao = new CntrIAAutenticacao();
    ISAutenticacao *cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrIAAutenticacao->setCntrISAutenticacao(cntrServicoAutenticacao);

    IAConta *cntrIAConta = new CntrIAConta();
    ISConta *cntrServicoConta = new CntrServicoConta();
    cntrIAConta->setCntrISConta(cntrServicoConta);

    bool resultado;
    CPF cpf;
    Senha senha;

    while (true) {
        cout << endl;
        cout << "                    UnBFixMon System                  " << endl;
        cout << endl;
        cout << "  _    _       ____  ______ _      __  __             " << endl;
        cout << " | |  | |     |  _  \|  ____(_)    |  \\/  |            " << endl;
        cout << " | |  | |_ __ | |_) | |__   ___  _| \\  / | ___  _ __  " << endl;
        cout << " | |  | |  _ \\|  _ <|  __| | \\ \\/ / |\\/| |/ _ \\|  _ \\ " << endl;
        cout << " | |__| | | | | |_) | |    | |>  <| |  | | (_) | | | |" << endl;
        cout << "  \\____/|_| |_|____/|_|    |_/_/\\_\\_|  |_|\\___/|_| |_|" << endl;
        cout << "                                                      " << endl;
        cout << endl;
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
                    bool exitMenu = false;
                    while (!exitMenu) {
                        cout << endl;
                        cout << "#########################################" << endl;
                        cout << "#              Menu Principal           #" << endl;
                        cout << "#########################################" << endl;
                        cout << endl;
                        cout << "1. Contas" << endl;
                        cout << "2. Investimentos" << endl;
                        cout << "3. Sair" << endl;
                        cout << "Selecione uma opcao: ";

                        cin >> opcao;

                        switch (opcao) {
                            case 1:
                                cntrIAConta->executar(cpf);
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
                                cout << endl << "Saindo..." << endl;
                                exitMenu = true;
                                break;

                            default:
                                cout << "Opcao invalida!" << endl;
                                break;
                        }
                    }
                } else {
                    cout << endl << "Falha na autenticacao." << endl;
                }
                break;

            case 2:
                cntrIAConta->criar();
                break;

            case 3:
                cout << "Saindo" << endl;
                delete cntrIAAutenticacao;
                delete cntrServicoAutenticacao;
                delete cntrIAConta;
                delete cntrServicoConta;
                return 0;

            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }

    return 0;
}
