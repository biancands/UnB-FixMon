#include <iostream>
#include "domains.h"

using namespace std;

// Class Dinheiro
void Dinheiro::validar(double valor)
{
    if (valor < 0 || valor > LIMITE)
        throw invalid_argument("Argumento invalido.");
}
void Dinheiro::setValor(double valor)
{
    validar(valor);
    this->valor = valor;
}

// Class Senha
void Senha::validar(const string& senha)
{
    if (senha.size() != 6)
        throw invalid_argument("Senha invalida! Nao possui 6 digitos.");
    if (senha[0] == '0')
        throw invalid_argument("Senha invalida! O primeiro digito nao eh diferente de zero.");
    for (string::size_type i = 0; i < senha.size(); i++)
    {
        if (!isdigit(senha[i]))
            throw invalid_argument("Senha invalida! Nao eh composta apenas por numeros.");
        for (string::size_type j = i + 1; j < senha.size(); j++)
        {
            if (senha[i] == senha[j])
                throw invalid_argument("Senha invalida! Possui digito duplicado.");
        }
    }
    bool isI = true, isD = true;
    for (string::size_type i = 0; i < senha.size() - 1; i++)
    {
        if (senha[i] >= senha[i + 1])
            isI = false;
        if (senha[i] <= senha[i + 1])
            isD = false;
    }
    if (isI || isD)
        throw invalid_argument("Senha invalida! Possui digitos sequenciais.");
}
void Senha::setValor(const string& valor)
{
    validar(valor);
    this->valor = valor;
}

// Class Codigo
void Codigo::setCodigo(string codigo)
{
    validar(codigo);
    this->codigo = codigo;
}

// Class CodigoPagamento
void CodigoPagamento::validar(string codigo) const
{
    if (codigo.size() != 8)
    {
        throw length_error("Valor nao esta no tamanho de caracteres permitidos!");
    }

    int count = 0;
    for (char c : codigo)
    {
        if (!isdigit(c) or (count == 0 && c == '0'))
        {
            throw invalid_argument("Valor invalido!");
        }
        count++;
    }
}

// Class CodigoTitulo
void CodigoTitulo::validar(string codigo) const
{
    string codCheck = codigo.substr(0, 3);
    bool verificador = true;
    auto it = find(listaTitulos.begin(), listaTitulos.end(), codCheck);

    if (codigo.size() != 11)
    {
        throw length_error("Valor do campo (CodigoTitulo) nao esta no tamanho permitido!");
    } else if (it == listaTitulos.end())
    {
        throw invalid_argument("Valor invalido! Codigo Titulo invalido. Lista validos: CDB, CRA, CRI, LCA, LCI e DEB.");
    } else
    {
        for (char c : codigo)
        {
            if (isupper(c))
            {
                verificador = true;
            } else if (isdigit(c))
            {
                verificador = true;
            } else
            {
                throw invalid_argument("Valor invalido! Contem letras minusculas ou simbolo.");
            }
        }
    }
}

// Class Estado
void Estado::validar(string estado)
{
    if (!(estado == "Previsto" || estado == "Liquidado" || estado == "Inadimplente"))
        throw invalid_argument("Argumento invalido.");
}

void Estado::setEstado(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Class CPF
void CPF::validar(string cpf)
{
    int digito;
    int resto;
    int soma1 = 0;
    int soma2 = 0;
    int peso = 0;
    if (cpf.size() != 14)
    {
        throw invalid_argument("CPF invalida! Nao possui 14 carcteres.");
    }
    if (cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-')
    {
        throw invalid_argument("CPF invalida! Pontuacao errada.");
    }
    for (int i = 0; i < 14; i++)
    {
        if (i == 3 || i == 7 || i == 11) { continue; }
        else
        {
            if (!isdigit(cpf[i]))
            {
                throw invalid_argument("CPF invalida! Nao e digito.");
            } else if (i == 13)
            {
                digito = cpf[i] - '0';
                resto = soma2 % 11;
                if (resto == 10) { resto = 0; }
                if (resto != digito) {
                    throw invalid_argument("CPF invalida!");
                }
            } else if (i == 12)
            {
                digito = cpf[i] - '0';
                resto = soma1 % 11;
                if (resto == 10) { resto = 0; }
                if (resto != digito)
                {
                    throw invalid_argument("CPF invalida!");
                } else { soma2 = soma2 + digito * peso; }
            } else
            {
                digito = cpf[i] - '0';
                soma1 = soma1 + (digito * (peso + 1));
                soma2 = soma2 + digito * peso;
                peso = peso + 1;
            }
        }
    }
}
void CPF::setCPF(string valor)
{
    validar(valor);
    this->valor = valor;
}

// Class Data
Data::Data() : dia(0), mes(0), ano(0) {}
Data::Data(const std::string& data)
{
    setData(data);
}

void Data::setData(const std::string& data)
{
    int d, m, a;
    validarFormatoData(data, d, m, a);
    validarDia(d, m);
    validarMes(m);
    validarAno(a);
    dia = d;
    mes = m;
    ano = a;
}
std::string Data::getData() const
{
    std::stringstream ss;
    ss << (dia < 10 ? "0" : "") << dia << "-" << (mes < 10 ? "0" : "") << mes << "-" << ano;
    return ss.str();
}

void Data::validarDia(int d, int m) const
{
    if (d < 1 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) ||
        (m == 2 && ((ehBissexto(ano) && d > 29) || (!ehBissexto(ano) && d > 28))) ||
        (m != 2 && d > 31))
    {
        throw std::invalid_argument("Erro: Dia invalido");
    }
}
void Data::validarMes(int m) const
{
    if (m < 1 || m > 12)
    {
        throw std::invalid_argument("Erro: Mes invalido");
    }
}
void Data::validarAno(int a) const
{
    if (a < 2000 || a > 2100)
    {
        throw std::invalid_argument("Erro: Ano invalido");
    }
}
void Data::validarFormatoData(const std::string& data, int& d, int& m, int& a) const
{
    std::stringstream ss(data);
    char delim1, delim2;
    ss >> d >> delim1 >> m >> delim2 >> a;
    if (ss.fail() || ss.peek() != EOF || delim1 != '-' || delim2 != '-')
    {
        throw std::invalid_argument("Erro: Formato de data invalido");
    }
}
bool Data::ehBissexto(int a) const
{
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

// Class Percentual
void Percentual::setValor(int v)
{
    validarValor(v);
    valor = v;
}
int Percentual::getValor() const
{
    return valor;
}
void Percentual::validarValor(int v)
{
    if (v < 0 || v > 100)
    {
        throw invalid_argument("Erro: Valor invalido");
    }
}

// Class Nome
Nome::Nome(const string& primeiro, const string& segundo) : primeiro_nome(primeiro), sobrenome(segundo)
{
    validarTermo(primeiro);
    validarTermo(segundo);
}
string Nome::getPrimeiroNome() const
{
    return primeiro_nome;
}
string Nome::getSobreNome() const
{
    return sobrenome;
}
bool Nome::validarNome() const
{
    regex padrao("^([A-Z][a-z]{2,9})(\\s([A-Z][a-z]{2,9}))?$");
    return regex_match(primeiro_nome + ' ' + sobrenome, padrao);
}
void Nome::setPrimeiroNome(const string& primeiro)
{
    validarTermo(primeiro);
    primeiro_nome = primeiro;
}
void Nome::setSobreNome(const string& segundo)
{
    validarTermo(segundo);
    sobrenome = segundo;
}
void Nome::validarTermo(const string& termo) const
{
    if (termo.empty())
    {
        throw invalid_argument("Não pode ser vazio");
    }
    if (termo.size() < 3 || termo.size() > 10)
    {
        throw invalid_argument("O termo deve ter entre 3 e 10 caracteres");
    }
    if (!isupper(termo[0]))
    {
        throw invalid_argument("Todos os caracteres devem ser letras.");
    }
}

// Class Setor
const unordered_set<string> Setor::setoresValidos =
{
    "Agricultura",
    "Construção civil",
    "Energia",
    "Finanças",
    "Imobiliário",
    "Papel e celulose",
    "Pecuária",
    "Química e petroquímica",
    "Metalurgia e siderurgia",
    "Mineração"
};
Setor::Setor(const string& setor) : setorNome(setor)
{
    validarSetor();
}
string Setor::getSetorNome() const
{
    return setorNome;
}
void Setor::validarSetor() const
{
    if (setoresValidos.count(setorNome) == 0)
    {
        throw invalid_argument("invalido");
    }
}
void Setor::setSetorNome(const string& setor)
{
    setorNome = setor;
    validarSetor();
}
