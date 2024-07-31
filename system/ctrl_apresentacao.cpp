#include "ctrl_apresentacao.h"
#include "comandos.h"

using namespace std;

bool CntrIAAutenticacao::autenticar(CPF *cpf, Senha *senha) {
    bool resultado;
    std::string entradaCPF;
    std::string entradaSenha;

    while (true) {
        try {
            std::cout << "Digite o CPF: ";
            std::cin >> entradaCPF;
            cpf->setCPF(entradaCPF);

            std::cout << "Digite a senha: ";
            std::cin >> entradaSenha;
            senha->setValor(entradaSenha);

            break;
        }
        catch (const std::invalid_argument &exp) {
            std::cout << std::endl << "Dado em formato incorreto." << std::endl;
        }
    }

    resultado = cntrISAutenticacao->autenticar(cpf->getCPF(), senha->getValor());

    return resultado;
}

