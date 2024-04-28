#include "tests.h"
#include "entities.h"

void TUDinheiro::setUp(){
    dinheiro = new Dinheiro();
    estado = SUCESSO;
}

void TUDinheiro::tearDown(){
    delete dinheiro;
}

void TUDinheiro::testarCenarioSucesso(){
    try{
        dinheiro->setValor(VALOR_VALIDO);
        if (dinheiro->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioFalha(){
    try{
        dinheiro->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (dinheiro->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

void TUDinheiro::testarCenarioNegativo(){
    try{
        dinheiro->setValor(VALOR_NEGATIVO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (dinheiro->getValor() == VALOR_NEGATIVO)
            estado = FALHA;
    }
}

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioDuplicado(){
    try{
        senha->setValor(VALOR_DUPLICADO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_DUPLICADO)
            estado = FALHA;
    }
}

void TUSenha::testarCenarioZeroInicio(){
    try{
        senha->setValor(VALOR_ZERO_INICIO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_ZERO_INICIO)
            estado = FALHA;
    }
}

void TUSenha::testarCenarioCrescente(){
    try{
        senha->setValor(VALOR_CRESCENTE);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_CRESCENTE)
            estado = FALHA;
    }
}

void TUSenha::testarCenarioDecrescente(){
    try{
        senha->setValor(VALOR_DECRESCENTE);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_DECRESCENTE)
            estado = FALHA;
    }
}

void TUCodigoPagamento::setUp(){
    codigo = new CodigoPagamento();
    estado = SUCESSO;
}

void TUCodigoPagamento::tearDown(){
    delete codigo;
}

void TUCodigoPagamento::testCenarioCodValido(){

    try{
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

void TUCodigoPagamento::testCenarioCodInvalidoPrimeiroDigito(){

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

void TUCodigoPagamento::testCenarioCodTamanhoInvalido(){
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

void TUCodigoTitulo::setUp(){
    codigo = new CodigoTitulo();
    estado = SUCESSO;
}

void TUCodigoTitulo::tearDown(){
    delete codigo;
}

void TUCodigoTitulo::testCodValido(){

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

void TUCodigoTitulo::testCodInvalidoMinuscula(){

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


void TUCodigoTitulo::testCodInvalidoSimbolo(){

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

void TUCodigoTitulo::testCodTamanhoInvalido(){

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


void TUCodigoTitulo::testCodInvalidoTitulo(){

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

void TUEstado::setUp(){
    status = new Estado();
    estado = SUCESSO;
}

void TUEstado::tearDown(){
    delete status;
}

void TUEstado::testarCenarioSucesso(){
    try{
        status-> setEstado(VALOR_VALIDO);
        if(status->getEstado() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEstado::testarCenarioFalha(){
    try{
        status-> setEstado(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (status->getEstado() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

void TUCPF::setUp(){
    cpf = new CPF();
    estado = SUCESSO;
}

void TUCPF::tearDown(){
    delete cpf;
}

void TUCPF::testarCenarioSucesso(){
    try{
        cpf->setCPF(VALOR_VALIDO);
        if(cpf->getCPF() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha1(){
    try{
        cpf->setCPF(VALOR_INVALIDO1);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (cpf->getCPF() == VALOR_INVALIDO1)
            estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha2(){
    try{
        cpf->setCPF(VALOR_INVALIDO2);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (cpf->getCPF() == VALOR_INVALIDO2)
            estado = FALHA;
    }
}

const std::string TUData::DATA_VALIDA = "20-10-2010";
const std::string TUData::DATA_INVALIDA = "34-16-2599";

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioSucesso(){
    try{
        data->validarData(DATA_VALIDA);
        if (data->getDia() != VALOR_DIA_VALIDO || data->getMes() != VALOR_MES_VALIDO || data->getAno() != VALOR_ANO_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}


void TUData::testarCenarioFalha(){
    try{
        data->validarData(DATA_INVALIDA);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (data->getDia() == VALOR_DIA_INVALIDO && data->getMes() == VALOR_MES_INVALIDO && data->getAno() == VALOR_ANO_INVALIDO){
            estado = FALHA;
        }
    }
}

void TUPercentual::setUp(){
    percentual = new Percentual();
    estado = SUCESSO;
}

void TUPercentual::tearDown(){
    delete percentual;
}

void TUPercentual::testarCenarioSucesso(){
    try{
        percentual->setValor(VALOR_VALIDO);
        if (percentual->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUPercentual::testarCenarioFalha(){
    try{
        percentual->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (percentual->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

void TUNome::setUp(){
    nome = new Nome(PRIMEIRO_NOME_VALIDO, SOBRE_NOME_VALIDO);
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioSucesso() {
    try {
        nome ->setPrimeiroNome(PRIMEIRO_NOME_VALIDO);
        nome ->setSobreNome(SOBRE_NOME_VALIDO);
        if(!nome ->validarNome() ||
        nome ->getPrimeiroNome() != PRIMEIRO_NOME_VALIDO ||
        nome -> getSobreNome() != SOBRE_NOME_VALIDO){
            estado = FALHA;
        }
    }catch (exception& excecao){
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalhaPrimeiroNome(){
    try {
        nome -> setPrimeiroNome(PRIMEIRO_NOME_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao) {

    }
}

void TUNome::testarCenarioFalhaSobreNome(){
    try{
        nome -> setSobreNome(SOBRE_NOME_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao) {

    }
}

void TUSetor::setUp(){
    setor = new Setor(SETOR_VALIDO);
    estado = SUCESSO;
}

void TUSetor::teardown(){
    delete setor;
}

void TUSetor::testarSetorValido(){
    try{
        setor ->setSetorNome(SETOR_VALIDO);
        if (setor->getSetorNome() != SETOR_VALIDO)
            estado = FALHA;
    } catch (invalid_argument& excecao){
        estado = FALHA;
    }
}

void TUSetor::testarSetorInvalido(){
    try{
        setor ->setSetorNome(SETOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument& excecao){

    }
}


int TUDinheiro::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    testarCenarioNegativo();
    tearDown();
    return estado;
}

int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioDuplicado();
    testarCenarioZeroInicio();
    testarCenarioCrescente();
    testarCenarioDecrescente();
    tearDown();
    return estado;
}

int TUCodigoPagamento::run(){
    setUp();
    testCenarioCodValido();
    testCenarioCodInvalidoPrimeiroDigito();
    testCenarioCodTamanhoInvalido();
    return estado;
}

int TUCodigoTitulo::run(){

    setUp();
    testCodValido();
    testCodInvalidoMinuscula();
    testCodInvalidoTitulo();
    testCodInvalidoSimbolo();
    testCodTamanhoInvalido();
    tearDown();
    return estado;
}

int TUEstado::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

int TUCPF::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha1();
    testarCenarioFalha2();
    tearDown();
    return estado;
}

int TUData::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

int TUPercentual::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

int TUNome::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalhaPrimeiroNome();
    testarCenarioFalhaSobreNome();
    tearDown();
    return estado;
}

int TUSetor::run(){
    setUp();
    testarSetorValido();
    testarSetorInvalido();
    teardown();
    return estado;
}
