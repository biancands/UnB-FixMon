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
    string textotitulo;

    while(true) {
        cout << endl << "Menu de Investimentos" << endl;
        cout << "1. Titulos" << endl;
        cout << "2. Pagamentos" << endl;
        cout << "3. Sair" << endl;
        cout << "Selecione uma opcao: ";
        cin >> opcao;
        switch (opcao) {
            case 1: {
                while(true){
                cout << endl << "Menu de Titulos" << endl;
                cout << "1. Criar Titulo" << endl;
                cout << "2. Ler Titulo" << endl;
                cout << "3. Atualizar Titulo" << endl;
                cout << "4. Excluir Titulo" << endl;
                cout << "5. Sair" << endl;
                cout << "Selecione uma opcao: ";
                cin >> opcao;
                switch(opcao){
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

                    cout << "Digite o codigo do titulo: ";
                    cin >> codigoStr;
                    codigo.setCodigo(codigoStr);
                    titulo.setCodigo(codigo);

                    cout << "Digite o primeiro nome do emissor: ";
                    cin >> emissorStr;
                    emissor.setPrimeiroNome(emissorStr);

                    cout << "Digite o segundo nome do emissor: ";
                    cin >> emissorStr;
                    emissor.setSobreNome(emissorStr);
                    titulo.setEmissorUm(emissor);

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
                    break;
                    }
                    case 2: {
                    // Ler Titulo
                    CodigoTitulo codigo;
                    string codigoStr;
                    Titulo titulo;

                    cout << "Digite o codigo do titulo: ";
                    cin >> codigoStr;
                    codigo.setCodigo(codigoStr);
                    titulo.setCodigo(codigo);

                    resultado = cntrISInvestimento->ler(&titulo);
                    if (resultado) {
                        cout << "Titulo lido com sucesso!" << endl;
                        //cout << "Codigo: " << titulo.getCodigo().getCodigo << endl;
                        //cout << "Nome: " << titulo.getEmissorUm.getPrimeiroNome << " " << titulo.getEmissorUm.getSobreNome << endl;
                        //cout << "Setor: " << titulo.getSetor.getSetorNome << endl;
                        //cout << "Data de Emissao: " << titulo.getEmissao.getData << endl;
                        //cout << "Data de Vencimento: " << titulo.getVencimento.getData << endl;
                        //cout << "Valor: " << titulo.getValor.getValor << endl;
                    } else {
                        cout << "Falha ao ler titulo." << endl;
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

                    cout << "Digite o codigo do titulo: ";
                    cin >> codigoStr;
                    codigo.setCodigo(codigoStr);
                    titulo.setCodigo(codigo);

                    cout << "Digite o primeiro nome do emissor: ";
                    cin >> emissorStr;
                    emissor.setPrimeiroNome(emissorStr);

                    cout << "Digite o segundo nome do emissor: ";
                    cin >> emissorStr;
                    emissor.setSobreNome(emissorStr);

                    titulo.setEmissorUm(emissor);

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
                    break;
                    }
                    case 4: {
                    // Excluir Titulo
                    CodigoTitulo codigo;
                    string codigoStr;

                    cout << "Digite o codigo do titulo: ";
                    cin >> codigoStr;
                    codigo.setCodigo(codigoStr);

                    resultado = cntrISInvestimento->excluir(codigo);
                    if (resultado) {
                        cout << "Titulo excluido com sucesso!" << endl;
                    } else {
                        cout << "Falha ao excluir titulo." << endl;
                    }
                    break;

                    }
                    case 5:
                    cout << "Saindo do menu de investimentos" << endl;
                    return;
                    default:
                    cout << "Opcao invalida!" << endl;
                    break;
                    }
            }
            case 2: {
                while(true){
                cout << endl << "Menu de Pagamentos" << endl;
                cout << "1. Criar Pagamento" << endl;
                cout << "2. Ler Pagamento" << endl;
                cout << "3. Atualizar Pagamento" << endl;
                cout << "4. Excluir Pagamento" << endl;
                cout << "5. Sair" << endl;
                cout << "Selecione uma opcao: ";
                cin >> opcao;
                switch(opcao){
                case 1: {
                // Criar Pagamento
                Pagamento pagamento;
                CodigoPagamento codigo;
                Data data;
                Percentual percentual;
                Estado estado;

                string codigoStr, dataStr, estadoStr;
                int percentualInt;

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
                break;
                }
                case 2: {
                // Ler Pagamento
                CodigoPagamento codigo;
                string codigoStr;
                Pagamento pagamento;

                cout << "Digite o codigo do pagamento: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);
                pagamento.setCodigo(codigo);

                resultado = cntrISInvestimento->ler(&pagamento);
                if (resultado) {
                    cout << "Pagamento lido com sucesso!" << endl;
                    //cout << "Codigo: " << pagamento.getCodigo.getCodigo << endl;
                    //cout << "Data: " << pagamento.getData.getData << endl;
                    //cout << "Percentual: " << pagamento.getPercentual.getValor << endl;
                    //cout << "Estado: " << pagamento.getEstado.getEstado << endl;
                    // Exibir os dados do pagamento
                } else {
                    cout << "Falha ao ler pagamento." << endl;
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
                break;
                }
                case 4: {
                // Excluir Pagamento
                CodigoPagamento codigo;
                string codigoStr;

                cout << "Digite o codigo do pagamento: ";
                cin >> codigoStr;
                codigo.setCodigo(codigoStr);

                resultado = cntrISInvestimento->excluir(codigo);
                if (resultado) {
                    cout << "Pagamento excluido com sucesso!" << endl;
                } else {
                    cout << "Falha ao excluir pagamento." << endl;
                }
                break;
                }
                case 5:
                cout << "Saindo do menu de investimentos" << endl;
                return;
                default:
                cout << "Opcao invalida!" << endl;
                break;

                }
                }
                break;
            }
            case 3: {
            cout << "Saindo do menu de investimentos" << endl;
            return;
            default:
            cout << "Opcao invalida!" << endl;
            break;
            }

        }
    }



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

            }

        }
    }
}

