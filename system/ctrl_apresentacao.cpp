#include "ctrl_apresentacao.h"

using namespace std;
//200040979
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

void CntrIAConta::criar() {
    string entrada;
    Conta conta;

    CPF cpf;
    Nome nome_um("Compreenda", "Oponto");
    Nome nome_dois("Compreenda", "Oponto");
    Senha senha;

    cout << "Digite o CPF: ";
    cin >> entrada;
    cpf.setCPF(entrada);

    cout << "Digite o primeiro nome: ";
    cin >> entrada;
    nome_um.setPrimeiroNome(entrada);

    cout << "Digite o sobrenome: ";
    cin >> entrada;
    nome_dois.setSobreNome(entrada);

    cout << "Digite a senha: ";
    cin >> entrada;
    senha.setValor(entrada);

    conta.setNumCPF(cpf);
    conta.setNomeUm(nome_um);
    conta.setNomeDois(nome_dois);
    conta.setSenha(senha);

    if (cntrISConta->criar(conta)) {
        cout << "Conta criada com sucesso!" << endl;
    } else {
        cout << "Falha na criação da conta." << endl;
    }
}

int CntrIAConta::executar(const CPF &cpf) {
    Conta conta;
    conta.setNumCPF(cpf);

    if (!cntrISConta->ler(&conta)) {
        cout << "Conta nao encontrada." << endl;
        return 0;
    }

    int opcao;
    string entrada;
    Nome nome_um("Ponto", "Compreendido");
    Nome nome_dois("Ponto", "Compreendido");
    Senha senha;

    cout << "1. Ver Conta" << endl;
    cout << "2. Atualizar Conta" << endl;
    cout << "3. Excluir Conta" << endl;
    cout << "Selecione uma opcao: ";

    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "CPF: " << conta.getNumCPF().getCPF() << endl;
            cout << "Primeiro Nome: " << conta.getNomeUm().getPrimeiroNome() << endl;
            cout << "Sobrenome: " << conta.getNomeDois().getSobreNome() << endl;
            cout << "Senha: " << conta.getSenha().getValor() << endl;
            break;

        case 2:
            cout << "Digite o novo primeiro nome: ";
            cin >> entrada;
            nome_um.setPrimeiroNome(entrada);
            conta.setNomeUm(nome_um);

            cout << "Digite o novo sobrenome: ";
            cin >> entrada;
            nome_dois.setSobreNome(entrada);
            conta.setNomeDois(nome_dois);

            cout << "Digite a nova senha: ";
            cin >> entrada;
            senha.setValor(entrada);
            conta.setSenha(senha);

            if (cntrISConta->atualizar(conta)) {
                cout << "Conta atualizada com sucesso!" << endl;
            } else {
                cout << "Falha na atualização da conta." << endl;
            }
            break;

        case 3:
            if (cntrISConta->excluir(cpf)) {
                cout << "Conta excluida com sucesso!" << endl;
            } else {
                cout << "Falha na exclusao da conta." << endl;
            }
            break;

        default:
            cout << "Opção invalida." << endl;
            break;
    }

    return 0;
}
