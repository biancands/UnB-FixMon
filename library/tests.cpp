#include "tests.h"
#include "entities.h"
#include "domains.h"

//========================== TESTE DOMINIOS ========================================================

//class TUDinheiro
void TUDinheiro::setUp()
{
    dinheiro = new Dinheiro();
    estado = SUCESSO;
}
void TUDinheiro::tearDown(){
    delete dinheiro;
}
void TUDinheiro::testarCenarioSucesso()
{
    try
    {
        dinheiro->setValor(VALOR_VALIDO);
        if (dinheiro->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
void TUDinheiro::testarCenarioFalha()
{
    try
    {
        dinheiro->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (dinheiro->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
void TUDinheiro::testarCenarioNegativo()
{
    try
    {
        dinheiro->setValor(VALOR_NEGATIVO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (dinheiro->getValor() == VALOR_NEGATIVO)
            estado = FALHA;
    }
}
int TUDinheiro::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    testarCenarioNegativo();
    tearDown();
    return estado;
}

//================================================================================================================================

//class TUSenha
void TUSenha::setUp()
{
    senha = new Senha();
    estado = SUCESSO;
}
void TUSenha::tearDown()
{
    delete senha;
}
void TUSenha::testarCenarioSucesso()
{
    try
    {
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
void TUSenha::testarCenarioDuplicado()
{
    try
    {
        senha->setValor(VALOR_DUPLICADO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (senha->getValor() == VALOR_DUPLICADO)
            estado = FALHA;
    }
}
void TUSenha::testarCenarioZeroInicio()
{
    try
    {
        senha->setValor(VALOR_ZERO_INICIO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (senha->getValor() == VALOR_ZERO_INICIO)
            estado = FALHA;
    }
}
void TUSenha::testarCenarioCrescente()
{
    try
    {
        senha->setValor(VALOR_CRESCENTE);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (senha->getValor() == VALOR_CRESCENTE)
            estado = FALHA;
    }
}
void TUSenha::testarCenarioDecrescente()
{
    try
    {
        senha->setValor(VALOR_DECRESCENTE);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (senha->getValor() == VALOR_DECRESCENTE)
            estado = FALHA;
    }
}
int TUSenha::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioDuplicado();
    testarCenarioZeroInicio();
    testarCenarioCrescente();
    testarCenarioDecrescente();
    tearDown();
    return estado;
}

// =================================================================================================

//class TUCodigoPagamento
void TUCodigoPagamento::setUp()
{
    codigo = new CodigoPagamento();
    estado = SUCESSO;
}
void TUCodigoPagamento::tearDown()
{
    delete codigo;
}
void TUCodigoPagamento::testCenarioCodValido()
{
    try
    {
        codigo->setCodigo(CODIGO_VALIDO);
        if (codigo->getCodigo() != CODIGO_VALIDO)
        {
            estado = FALHA;
        }

    }
    catch(invalid_argument &e)
    {
        estado = FALHA;
    }
}
void TUCodigoPagamento::testCenarioCodInvalidoPrimeiroDigito()
{
    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_PRIMEIRO_DIGITO);
        estado=FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_PRIMEIRO_DIGITO)
        {
            estado=FALHA;
        }
    }
}
void TUCodigoPagamento::testCenarioCodTamanhoInvalido()
{
    try
    {
        codigo->setCodigo(CODIGO_TAMANHO_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &e)
    {
        if (codigo->getCodigo() == CODIGO_TAMANHO_INVALIDO)
        {
            estado=FALHA;
        }
    }

}
int TUCodigoPagamento::run()
{
    setUp();
    testCenarioCodValido();
    testCenarioCodInvalidoPrimeiroDigito();
    testCenarioCodTamanhoInvalido();
    return estado;
}

//==========================================================================================================================

//class TUCodigoTitulo
void TUCodigoTitulo::setUp()
{
    codigo = new CodigoTitulo();
    estado = SUCESSO;
}
void TUCodigoTitulo::tearDown()
{
    delete codigo;
}
void TUCodigoTitulo::testCodValido()
{
    try
    {
        codigo->setCodigo(CODIGO_VALIDO);
        if (codigo->getCodigo() != CODIGO_VALIDO)
        {
            estado = FALHA;
        }
    }
    catch(invalid_argument &e)
    {
        estado=FALHA;
    }

}
void TUCodigoTitulo::testCodInvalidoMinuscula()
{
    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_MINUSCULA);
        estado = FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_MINUSCULA)
            estado=FALHA;
    }

}
void TUCodigoTitulo::testCodInvalidoSimbolo()
{
    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_SIMBOLO);
        estado = FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_SIMBOLO)
            estado=FALHA;

    }

}
void TUCodigoTitulo::testCodTamanhoInvalido()
{
    try
    {
        codigo->setCodigo(CODIGO_TAMANHO_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &e)
    {
        if (codigo->getCodigo() == CODIGO_TAMANHO_INVALIDO)
            estado = FALHA;

    }

}
void TUCodigoTitulo::testCodInvalidoTitulo()
{
    try
    {
        codigo->setCodigo(CODIGO_INVALIDO_TITULO);
        estado = FALHA;
    }
    catch(invalid_argument &e)
    {
        if (codigo->getCodigo() == CODIGO_INVALIDO_TITULO)
            estado = FALHA;

    }

}
int TUCodigoTitulo::run()
{
    setUp();
    testCodValido();
    testCodInvalidoMinuscula();
    testCodInvalidoTitulo();
    testCodInvalidoSimbolo();
    testCodTamanhoInvalido();
    tearDown();
    return estado;
}

//================================================================================================================================

//class TUEstado
void TUEstado::setUp()
{
    status = new Estado();
    estado = SUCESSO;
}
void TUEstado::tearDown()
{
    delete status;
}
void TUEstado::testarCenarioSucesso()
{
    try
    {
        status-> setEstado(VALOR_VALIDO);
        if(status->getEstado() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
void TUEstado::testarCenarioFalha()
{
    try
    {
        status-> setEstado(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (status->getEstado() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUEstado::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//==================================================================================================================

//class TUCPF
void TUCPF::setUp()
{
    cpf = new CPF();
    estado = SUCESSO;
}
void TUCPF::tearDown()
{
    delete cpf;
}
void TUCPF::testarCenarioSucesso()
{
    try
    {
        cpf->setCPF(VALOR_VALIDO);
        if(cpf->getCPF() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
void TUCPF::testarCenarioFalha1()
{
    try
    {
        cpf->setCPF(VALOR_INVALIDO1);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (cpf->getCPF() == VALOR_INVALIDO1)
            estado = FALHA;
    }
}
void TUCPF::testarCenarioFalha2()
{
    try
    {
        cpf->setCPF(VALOR_INVALIDO2);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (cpf->getCPF() == VALOR_INVALIDO2)
            estado = FALHA;
    }
}
int TUCPF::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha1();
    testarCenarioFalha2();
    tearDown();
    return estado;
}

//=====================================================================================================================

//class TUData
const std::string TUData::DATA_VALIDA = "22-02-2024";
const std::string TUData::DATA_INVALIDA = "54-02-2599";

void TUData::setUp()
{
    data = new Data();
    estado = SUCESSO;
}
void TUData::tearDown()
{
    delete data;
}
void TUData::testarCenarioSucesso()
{
    try
    {
        data->setData(DATA_VALIDA);
        if (data->getData() != DATA_VALIDA)
        {
            estado = FALHA;
        }
    } catch (std::invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
void TUData::testarCenarioFalha()
{
    try
    {
        data->setData(DATA_INVALIDA);
        estado = FALHA;
    } catch (std::invalid_argument &excecao)
    {
        if (data->getData() == DATA_INVALIDA)
        {
            estado = FALHA;
        }
    }
}
int TUData::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//===========================================================================================================================

//class TUPercentual
void TUPercentual::setUp()
{
    percentual = new Percentual();
    estado = SUCESSO;
}
void TUPercentual::tearDown()
{
    delete percentual;
}
void TUPercentual::testarCenarioSucesso()
{
    try
    {
        percentual->setValor(VALOR_VALIDO);
        if (percentual->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
void TUPercentual::testarCenarioFalha()
{
    try
    {
        percentual->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if (percentual->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUPercentual::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//=======================================================================================================================

//class TUNome
void TUNome::setUp()
{
    nome = new Nome(PRIMEIRO_NOME_VALIDO, SOBRE_NOME_VALIDO);
    estado = SUCESSO;
}
void TUNome::tearDown()
{
    delete nome;
}
void TUNome::testarCenarioSucesso()
{
    try
    {
        nome ->setPrimeiroNome(PRIMEIRO_NOME_VALIDO);
        nome ->setSobreNome(SOBRE_NOME_VALIDO);
        if(!nome ->validarNome() ||
        nome ->getPrimeiroNome() != PRIMEIRO_NOME_VALIDO ||
        nome -> getSobreNome() != SOBRE_NOME_VALIDO){
            estado = FALHA;
        }
    }catch (exception& excecao)
    {
        estado = FALHA;
    }
}
void TUNome::testarCenarioFalhaPrimeiroNome()
{
    try
    {
        nome -> setPrimeiroNome(PRIMEIRO_NOME_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao)
    {

    }
}
void TUNome::testarCenarioFalhaSobreNome()
{
    try
    {
        nome -> setSobreNome(SOBRE_NOME_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao)
    {

    }
}
int TUNome::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalhaPrimeiroNome();
    testarCenarioFalhaSobreNome();
    tearDown();
    return estado;
}

//=========================================================================================================================

//class TUSetor
void TUSetor::setUp()
{
    setor = new Setor(SETOR_VALIDO);
    estado = SUCESSO;
}
void TUSetor::teardown()
{
    delete setor;
}
void TUSetor::testarSetorValido()
{
    try
    {
        setor ->setSetorNome(SETOR_VALIDO);
        if (setor->getSetorNome() != SETOR_VALIDO)
            estado = FALHA;
    } catch (invalid_argument& excecao)
    {
        estado = FALHA;
    }
}
void TUSetor::testarSetorInvalido()
{
    try
    {
        setor ->setSetorNome(SETOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao)
    {

    }
}
int TUSetor::run()
{
    setUp();
    testarSetorValido();
    testarSetorInvalido();
    teardown();
    return estado;
}

//=========================================== TESTE ENTIDADES =============================================================

//class TUConta
void TUConta::setUp()
{
    conta = new Conta();
    estado = SUCESSO;
}
void TUConta::tearDown()
{
    delete conta;
}
void TUConta::testarCenarioSucesso()
{
    CPF cpf;
    cpf.setCPF(CPF_VALIDO);
    conta->setNumCPF(cpf);
    if (conta->getNumCPF().getCPF() != CPF_VALIDO)
    {
        estado = FALHA;
    }

    Nome nome(PRIMEIRO_NOME_VALIDO, SOBRE_NOME_VALIDO);
    conta->setNomeUm(nome);
    conta->setNomeDois(nome);
    if (conta->getNomeUm().getPrimeiroNome() != PRIMEIRO_NOME_VALIDO || conta->getNomeDois().getSobreNome() != SOBRE_NOME_VALIDO)
    {
        estado = FALHA;
    }

    Senha senha;
    senha.setValor(SENHA_VALIDO);
    conta->setSenha(senha);
    if (conta->getSenha().getValor() != SENHA_VALIDO)
    {
        estado = FALHA;
    }
}
int TUConta::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

//===============================================================================================================

//class TUPagamento
void TUPagamento::setUp()
{
    pagamento = new Pagamento();
    estadoTest  = SUCESSO;
}
void TUPagamento::tearDown()
{
    delete pagamento;
}
void TUPagamento::testarCenarioSucesso()
{
    CodigoPagamento codigo;
    codigo.setCodigo(codigoPagamentoValido);
    pagamento->setCodigo(codigo);

    if(pagamento->getCodigo().getCodigo() != codigoPagamentoValido)
        estadoTest = FALHA;

    Data data(dataValida);
    pagamento->setData(data);
    if(pagamento->getData().getData() != dataValida)
        estadoTest = FALHA;

    Estado estado;
    estado.setEstado(estadoValido);
    pagamento->setEstado(estado);

    if(pagamento->getEstado().getEstado() != estadoValido)
        estadoTest = FALHA;

    Percentual percentual;
    percentual.setValor(percentualValido);
    pagamento->setPercentual(percentual);
    if(pagamento->getPercentual().getValor() != percentualValido)
        estadoTest = FALHA;
}
int TUPagamento::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estadoTest;
}

//========================================================================================================================

//class TUTitulo
void TUTitulo::setup()
{
    titulo = new Titulo();
    estadoTest = SUCESSO;
}
void TUTitulo::teardown()
{
    delete titulo;
}
void TUTitulo::testarCenarioSucesso()
{
    CodigoTitulo codigo;
    codigo.setCodigo(CODIGO_VALIDO);
    titulo ->setCodigo(codigo);
    if (titulo -> getCodigo().getCodigo() != CODIGO_VALIDO)
    {
        estadoTest = FALHA;
    }

    Nome nome(PRIMEIRO_NOME_VALIDO, SOBRE_NOME_VALIDO);
    titulo->setEmissorUm(nome);
    titulo->setEmissorDois(nome);
    if (titulo->getEmissorUm().getPrimeiroNome() != PRIMEIRO_NOME_VALIDO || titulo->getEmissorDois().getSobreNome() != SOBRE_NOME_VALIDO)
    {
        estadoTest = FALHA;
    }

    Setor setor(SETOR_VALIDO);
    titulo -> setSetor(setor);
    if (titulo -> getSetor(). getSetorNome() != SETOR_VALIDO)
    {
        estadoTest = FALHA;
    }

    Data emissao(DATA_VALIDA);
    titulo ->setEmissao(emissao);
    if (titulo ->getEmissao().getData() != DATA_VALIDA)
    {
        estadoTest = FALHA;
    }

    Data vencimento;
    vencimento.setData(DATA_VALIDA);
    titulo -> setVencimento(vencimento);
    if (titulo -> getVencimento().getData() != DATA_VALIDA)
    {
        estadoTest = FALHA;
    }

    Dinheiro valor;

    valor.setValor(VALOR_VALIDO);
    titulo -> setValor(valor);
    if (titulo -> getValor(). getValor() != VALOR_VALIDO)
    {
        estadoTest = FALHA;
    }
}
int TUTitulo::run()
{
    setup();
    testarCenarioSucesso();
    teardown();
    return estadoTest;
}
