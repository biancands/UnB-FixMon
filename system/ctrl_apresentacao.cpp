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
        cout << "1. Titulos" << endl;
        cout << "2. Pagamentos" << endl;
        cout << "3. Sair" << endl;
        cout << "Selecione uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                bool exitTitulosMenu = false;
                while (!exitTitulosMenu) {
                    cout << endl << "Menu de Titulos" << endl;
                    cout << "1. Criar Titulo" << endl;
                    cout << "2. Ler Titulo" << endl;
                    cout << "3. Atualizar Titulo" << endl;
                    cout << "4. Excluir Titulo" << endl;
                    cout << "5. Sair" << endl;
                    cout << "Selecione uma opcao: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1: {
                            // Criar Titulo
                            Titulo titulo;
                            CodigoTitulo codigo;
                            Nome emissorUm("Nome", "Valido");
                            Nome emissorDois("Nome", "Valido");
                            Setor setor("Agricultura");
                            Data emissao, vencimento;
                            Dinheiro valor;

                            string codigoStr, primeiroNomeEmissorStr, segundoNomeEmissorStr, setorStr, emissaoStr, vencimentoStr;
                            double valorDouble;

                            try {
                                cout << "Digite o codigo do titulo: ";
                                cin >> codigoStr;
                                codigo.setCodigo(codigoStr);
                                titulo.setCodigo(codigo);

                                cout << "Digite o primeiro nome do emissor: ";
                                cin >> primeiroNomeEmissorStr;
                                emissorUm.setPrimeiroNome(primeiroNomeEmissorStr);

                                cout << "Digite o segundo nome do emissor: ";
                                cin >> segundoNomeEmissorStr;
                                emissorDois.setSobreNome(segundoNomeEmissorStr);

                                titulo.setEmissorUm(emissorUm);
                                titulo.setEmissorDois(emissorDois);

                                cout << "Digite o setor: ";
                                cin >> setorStr;
                                setor.setSetorNome(setorStr);
                                titulo.setSetor(setor);

                                cout << "Digite a data de emissao (DD-MM-AAAA): ";
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
                                    cout << "Titulo criado com sucesso!" << endl;
                                } else {
                                    cout << "Falha ao criar titulo." << endl;
                                }
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 2: {
                            // Ler Titulo
                            CodigoTitulo codigo;
                            string codigoStr;
                            Titulo titulo;

                            try {
                                cout << "Digite o codigo do titulo: ";
                                cin >> codigoStr;
                                codigo.setCodigo(codigoStr);
                                titulo.setCodigo(codigo);

                                resultado = cntrISInvestimento->ler(&titulo);
                                if (resultado) {
                                    cout << "Título lido com sucesso!" << endl;
                                    cout << "Código: " << titulo.getCodigo().getCodigo() << endl;
                                    cout << "Emissor: " << titulo.getEmissorUm().getPrimeiroNome() << " " << titulo.getEmissorDois().getSobreNome() << endl;
                                    cout << "Setor: " << titulo.getSetor().getSetorNome() << endl;
                                    cout << "Data de Emissão: " << titulo.getEmissao().getData() << endl;
                                    cout << "Data de Vencimento: " << titulo.getVencimento().getData() << endl;
                                    cout << "Valor: " << titulo.getValor().getValor() << endl;
                                } else {
                                    cout << "Falha ao ler título." << endl;
                                }
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 3: {
                            // Atualizar Titulo
                            Titulo titulo;
                            CodigoTitulo codigo;
                            Nome emissorUm("Nome", "Valido");
                            Nome emissorDois("Nome", "Valido");
                            Setor setor("Agricultura");
                            Data emissao, vencimento;
                            Dinheiro valor;

                            string codigoStr, primeiroNomeEmissorStr, segundoNomeEmissorStr, setorStr, emissaoStr, vencimentoStr;
                            double valorDouble;

                            try {
                                cout << "Digite o codigo do titulo: ";
                                cin >> codigoStr;
                                codigo.setCodigo(codigoStr);
                                titulo.setCodigo(codigo);

                                cout << "Digite o primeiro nome do emissor: ";
                                cin >> primeiroNomeEmissorStr;
                                emissorUm.setPrimeiroNome(primeiroNomeEmissorStr);

                                cout << "Digite o segundo nome do emissor: ";
                                cin >> segundoNomeEmissorStr;
                                emissorDois.setSobreNome(segundoNomeEmissorStr);

                                titulo.setEmissorUm(emissorUm);
                                titulo.setEmissorDois(emissorDois);

                                cout << "Digite o setor: ";
                                cin >> setorStr;
                                setor.setSetorNome(setorStr);
                                titulo.setSetor(setor);

                                cout << "Digite a data de emissao (DD-MM-AAAA): ";
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
                                    cout << "Titulo atualizado com sucesso!" << endl;
                                } else {
                                    cout << "Falha ao atualizar titulo." << endl;
                                }
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 4: {
                            // Excluir Titulo
                            CodigoTitulo codigo;
                            string codigoStr;

                            try {
                                cout << "Digite o codigo do titulo: ";
                                cin >> codigoStr;
                                codigo.setCodigo(codigoStr);

                                resultado = cntrISInvestimento->excluir(codigo);
                                if (resultado) {
                                    cout << "Titulo excluido com sucesso!" << endl;
                                } else {
                                    cout << "Falha ao excluir titulo." << endl;
                                }
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 5:
                            exitTitulosMenu = true;
                            break;
                        default:
                            cout << "Opcao invalida!" << endl;
                            break;
                    }
                }
                break;
            }
            case 2: {
                bool exitPagamentosMenu = false;
                while (!exitPagamentosMenu) {
                    cout << endl << "Menu de Pagamentos" << endl;
                    cout << "1. Criar Pagamento" << endl;
                    cout << "2. Ler Pagamento" << endl;
                    cout << "3. Atualizar Pagamento" << endl;
                    cout << "4. Excluir Pagamento" << endl;
                    cout << "5. Sair" << endl;
                    cout << "Selecione uma opcao: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1: {
                            // Criar Pagamento
                            Pagamento pagamento;
                            CodigoPagamento codigo;
                            Data data;
                            Percentual percentual;
                            Estado estado;

                            string codigoStr, dataStr, estadoStr;
                            int percentualInt;

                            try {
                                cout << "Digite o codigo do pagamento: ";
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
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 2: {
                            // Ler Pagamento
                            CodigoPagamento codigo;
                            string codigoStr;
                            Pagamento pagamento;

                            try {
                                cout << "Digite o codigo do pagamento: ";
                                cin >> codigoStr;
                                codigo.setCodigo(codigoStr);
                                pagamento.setCodigo(codigo);

                                resultado = cntrISInvestimento->ler(&pagamento);
                                if (resultado) {
                                    cout << "Pagamento lido com sucesso!" << endl;
                                    cout << "Código: " << pagamento.getCodigo().getCodigo() << endl;
                                    cout << "Data: " << pagamento.getData().getData() << endl;
                                    cout << "Percentual: " << pagamento.getPercentual().getValor() << endl;
                                    cout << "Estado: " << pagamento.getEstado().getEstado() << endl;
                                } else {
                                    cout << "Falha ao ler pagamento." << endl;
                                }
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 3: {
                            // Atualizar Pagamento
                            Pagamento pagamento;
                            CodigoPagamento codigo;
                            Data data;
                            Percentual percentual;
                            Estado estado;

                            string codigoStr, dataStr, estadoStr;
                            int percentualInt;

                            try {
                                cout << "Digite o codigo do pagamento: ";
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
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 4: {
                            // Excluir Pagamento
                            CodigoPagamento codigo;
                            string codigoStr;

                            try {
                                cout << "Digite o codigo do pagamento: ";
                                cin >> codigoStr;
                                codigo.setCodigo(codigoStr);

                                resultado = cntrISInvestimento->excluir(codigo);
                                if (resultado) {
                                    cout << "Pagamento excluido com sucesso!" << endl;
                                } else {
                                    cout << "Falha ao excluir pagamento." << endl;
                                }
                            } catch (const std::invalid_argument &exp) {
                                cout << "Erro: " << exp.what() << endl;
                            }
                            break;
                        }
                        case 5:
                            exitPagamentosMenu = true;
                            break;
                        default:
                            cout << "Opcao invalida!" << endl;
                            break;
                    }
                }
                break;
            }
            case 3:
                cout << "Saindo do menu de investimentos" << endl;
                return;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }
}
