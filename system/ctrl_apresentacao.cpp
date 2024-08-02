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

void CntrIAInvestimento::executar(const CPF& cpf) {
    int opcao;
    bool resultado;

    while (true) {
        cout << endl << "Menu de Investimentos" << endl;
        cout << "1. Criar Titulo" << endl;
        cout << "2. Ler Titulo" << endl;
        cout << "3. Atualizar Titulo" << endl;
        cout << "4. Excluir Titulo" << endl;
        cout << "5. Criar Pagamento" << endl;
        cout << "6. Ler Pagamento" << endl;
        cout << "7. Atualizar Pagamento" << endl;
        cout << "8. Excluir Pagamento" << endl;
        cout << "9. Sair" << endl;
        cout << "Selecione uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                // Criar Titulo
                Titulo titulo;
                CodigoTitulo codigo;
                Nome emissor("Nome", "Valido");
                Setor setor("Agricultura");
                Data emissao, vencimento;
                Dinheiro valor;

                string codigoStr, emissorStr, setorStr, emissaoStr, vencimentoStr;
                double valorDouble;

                cout << "Digite o código do título: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                titulo.setCodigo(codigo);

                cout << "Digite o nome do emissor: ";
                cin >> emissorStr;
                emissor.setPrimeiroNome(emissorStr);
                titulo.setEmissorUm(emissor);

                cout << "Digite o setor: ";
                cin >> setorStr;
                setor.setSetorNome(setorStr);
                titulo.setSetor(setor);

                cout << "Digite a data de emissão (DD-MM-AAAA): ";
                cin >> emissaoStr;
                emissao.setData(emissaoStr);
                titulo.setEmissao(emissao);

                cout << "Digite a data de vencimento (DD-MM-AAAA): ";
                cin >> vencimentoStr;
                vencimento.setData(vencimentoStr);
                titulo.setVencimento(vencimento);

                cout << "Digite o valor: ";
                cin >> valorDouble;
                valor.setValor(valorDouble);
                titulo.setValor(valor);

                resultado = cntrISInvestimento->criar(titulo);
                if (resultado) {
                    cout << "Título criado com sucesso!" << endl;
                } else {
                    cout << "Falha ao criar título." << endl;
                }
                break;
            }
            case 2: {
                // Ler Titulo
                CodigoTitulo codigo;
                string codigoStr;
                Titulo titulo;

                cout << "Digite o código do título: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                titulo.setCodigo(codigo);

                resultado = cntrISInvestimento->ler(&titulo);
                if (resultado) {
                    cout << "Título lido com sucesso!" << endl;
                    // Exibir os dados do título
                } else {
                    cout << "Falha ao ler título." << endl;
                }
                break;
            }
            case 3: {
                // Atualizar Titulo
                Titulo titulo;
                CodigoTitulo codigo;
                Nome emissor("Nome", "Valido");
                Setor setor("Agricultura");
                Data emissao, vencimento;
                Dinheiro valor;

                string codigoStr, emissorStr, setorStr, emissaoStr, vencimentoStr;
                double valorDouble;

                cout << "Digite o código do título: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                titulo.setCodigo(codigo);

                cout << "Digite o nome do emissor: ";
                cin >> emissorStr;
                emissor.setPrimeiroNome(emissorStr);
                titulo.setEmissorUm(emissor);

                cout << "Digite o setor: ";
                cin >> setorStr;
                setor.setSetorNome(setorStr);
                titulo.setSetor(setor);

                cout << "Digite a data de emissão (DD-MM-AAAA): ";
                cin >> emissaoStr;
                emissao.setData(emissaoStr);
                titulo.setEmissao(emissao);

                cout << "Digite a data de vencimento (DD-MM-AAAA): ";
                cin >> vencimentoStr;
                vencimento.setData(vencimentoStr);
                titulo.setVencimento(vencimento);

                cout << "Digite o valor: ";
                cin >> valorDouble;
                valor.setValor(valorDouble);
                titulo.setValor(valor);

                resultado = cntrISInvestimento->atualizar(titulo);
                if (resultado) {
                    cout << "Título atualizado com sucesso!" << endl;
                } else {
                    cout << "Falha ao atualizar título." << endl;
                }
                break;
            }
            case 4: {
                // Excluir Titulo
                CodigoTitulo codigo;
                string codigoStr;

                cout << "Digite o código do título: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);

                resultado = cntrISInvestimento->excluir(codigo);
                if (resultado) {
                    cout << "Título excluído com sucesso!" << endl;
                } else {
                    cout << "Falha ao excluir título." << endl;
                }
                break;
            }
            case 5: {
                // Criar Pagamento
                Pagamento pagamento;
                CodigoPagamento codigo;
                Data data;
                Percentual percentual;
                Estado estado;

                string codigoStr, dataStr, estadoStr;
                int percentualInt;

                cout << "Digite o código do pagamento: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                pagamento.setCodigo(codigo);

                cout << "Digite a data do pagamento (DD-MM-AAAA): ";
                cin >> dataStr;
                data.setData(dataStr);
                pagamento.setData(data);

                cout << "Digite o percentual do pagamento: ";
                cin >> percentualInt;
                percentual.setValor(percentualInt);
                pagamento.setPercentual(percentual);

                cout << "Digite o estado do pagamento (Previsto, Liquidado, Inadimplente): ";
                cin >> estadoStr;
                estado.setEstado(estadoStr);
                pagamento.setEstado(estado);

                resultado = cntrISInvestimento->criar(pagamento);
                if (resultado) {
                    cout << "Pagamento criado com sucesso!" << endl;
                } else {
                    cout << "Falha ao criar pagamento." << endl;
                }
                break;
            }
            case 6: {
                // Ler Pagamento
                CodigoPagamento codigo;
                string codigoStr;
                Pagamento pagamento;

                cout << "Digite o código do pagamento: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                pagamento.setCodigo(codigo);

                resultado = cntrISInvestimento->ler(&pagamento);
                if (resultado) {
                    cout << "Pagamento lido com sucesso!" << endl;
                    // Exibir os dados do pagamento
                } else {
                    cout << "Falha ao ler pagamento." << endl;
                }
                break;
            }
            case 7: {
                // Atualizar Pagamento
                Pagamento pagamento;
                CodigoPagamento codigo;
                Data data;
                Percentual percentual;
                Estado estado;

                string codigoStr, dataStr, estadoStr;
                int percentualInt;

                cout << "Digite o código do pagamento: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                pagamento.setCodigo(codigo);

                cout << "Digite a data do pagamento (DD-MM-AAAA): ";
                cin >> dataStr;
                data.setData(dataStr);
                pagamento.setData(data);

                cout << "Digite o percentual do pagamento: ";
                cin >> percentualInt;
                percentual.setValor(percentualInt);
                pagamento.setPercentual(percentual);

                cout << "Digite o estado do pagamento (Previsto, Liquidado, Inadimplente): ";
                cin >> estadoStr;
                estado.setEstado(estadoStr);
                pagamento.setEstado(estado);

                resultado = cntrISInvestimento->atualizar(pagamento);
                if (resultado) {
                    cout << "Pagamento atualizado com sucesso!" << endl;
                } else {
                    cout << "Falha ao atualizar pagamento." << endl;
                }
                break;
            }
            case 8: {
                // Excluir Pagamento
                CodigoPagamento codigo;
                string codigoStr;

                cout << "Digite o código do pagamento: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);

                resultado = cntrISInvestimento->excluir(codigo);
                if (resultado) {
                    cout << "Pagamento excluído com sucesso!" << endl;
                } else {
                    cout << "Falha ao excluir pagamento." << endl;
                }
                break;
            }
            case 9:
                cout << "Saindo do menu de investimentos" << endl;
                return;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }
}

