/**
 * @file domains.h
 * @brief Defini��es das classes que representam os dom�nios.
 * Desenvolvedores:
 * - BIANCA N. SILVA
 * - FABIO L. B. PARRA
 * - DANILO S. SILVA
 * - MARCELO J. C. ESPINDOLA
 * - JORGE L. C. A. SILVA
 */

#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <cctype>
#include <regex>

using namespace std;

/**
 * @brief Representa um valor monet�rio no sistema.
 *
 * Regras de formato:
 *
 * - valor em dinheiro que deve estar no intervalo de 0 a 1.000.000,00.
 *
 */
// Classe Dinheiro
// 231013583
class Dinheiro
{
private:
    static constexpr double LIMITE = 1000000.00;
    double valor;
    void validar(double);
public:
    /**
     * @brief Define o valor do dinheiro.
     * @param valor Valor do dinheiro a ser definido, entre 0 a 1.000.000,00.
     * @throw invalid_argument Se o valor estiver fora da regra de formato.
     */
    void setValor(double);
    /**
     * @brief Retorna o valor do dinheiro.
     * @return Valor monet�rio.
     */
    double getValor() const;
};

inline double Dinheiro::getValor() const
{
    return valor;
}

/**
 * @brief Representa uma senha no sistema.
 *
 * Regras de formato:
 *
 * - A senha deve ser composta por 6 d�gitos (0-9)
 * - O primeiro d�gito deve ser diferente de zero;
 * - N�o pode ocorrer d�gitos duplicados;
 * - N�o pode ser uma sequ�ncia crescente ou decrescente.
 *
 */
// Classe Senha
// 231013583
class Senha
{
private:
    string valor;
    void validar(const string&);
public:
     /**
     * @brief Define o valor da senha.
     * @param valor Senha definido com base nas regras de formatos.
     * @throw invalid_argument Se a senha n�o seguir o formato especificado.
     */
    void setValor(const string&);

    /**
     * @brief Retorna o valor da senha.
     * @return Senha.
     */
    string getValor() const;
};

inline string Senha::getValor() const
{
    return valor;
}

/**
 * @brief Classe base para representar diferentes tipos de c�digos no sistema.
 * Classe criada para ser utilizada como base para CodigoPagamento e CodigoTitulo
 */
// Classe C�digo
// Parra - 211020956
class Codigo
{
private:
    string codigo;
    virtual void validar(string codigo) const = 0;
public:
    /**
     * @brief Define o valor do c�digo.
     * @param codigo C�digo a ser definido.
     * @throw invalid_argument Se o c�digo n�o seguir o formato especificado.
     */
    void setCodigo(string);

    /**
     * @brief Retorna o valor do c�digo.
     * @return C�digo.
     */
    inline string getCodigo() { return codigo; }
};

/**
 * @brief Representa um c�digo de pagamento no sistema.
 *
 * Regras de formato:
 *
 * - O c�digo de pagamento deve seguir o formato XXXXXXXX, onde X � um d�gito (0-9)
 * - O primeiro d�gito deve ser diferente de zero (1-9).
 *
 */
// Classe C�digo Pagamento
// Parra - 211020956
class CodigoPagamento : public Codigo
{
private:
    void validar(string) const override;
};

/**
 * @brief Representa um c�digo de t�tulo no sistema.
 *
 *
 * Regras de formato:
 *
 * - O c�digo de t�tulo deve seguir um dos formatos prefixados (CDB, CRA, CRI, LCA, LCI, DEB) seguido de 8 caracteres,
 * - Cada caractere pode ser uma letra mai�scula (A-Z) ou um d�gito (0-9).
 *
 */
// Classe C�digo T�tulo
// Parra - 211020956
class CodigoTitulo : public Codigo
{
protected:
    void validar(string) const override;
public:
    vector<string> listaTitulos = {"CDB", "CRA", "CRI", "LCA", "LCI", "DEB"};
};

/**
 * @brief Representa o estado de uma entidade no sistema.
 *
 * Os estados permitidos s�o: "Previsto", "Liquidado" e "Inadimplente".
 *
 */
// Classe Estado
// 222014142
class Estado
{
private:
    string valor;
    void validar(string);
public:
     /**
     * @brief Define o estado.
     * @param estado Estado deve ser um dos seguintes valores: "Previsto", "Liquidado", "Inadimplente".
     * @throw invalid_argument Se o estado n�o for um dos valores permitidos.
     */
    void setEstado(string);
    string getEstado() const;
};

inline string Estado::getEstado() const {
    return valor;
}

/**
 * @brief Representa um CPF no sistema.
 *
 * Regras de formato:
 *
 * - O CPF deve seguir o formato XXX.XXX.XXX-CC, onde X � um d�gito (0-9)
 * - CC s�o caracteres de valida��o calculados segundo
 * o algoritmo de valida��o de CPF.
 *
 */
// Classe CPF
// 222014142
class CPF
{
private:
    string valor;
    void validar(string);
public:
    /**
     * @brief Define o CPF.
     * @param cpf CPF a ser definido no formato XXX.XXX.XXX-CC.
     * @throw invalid_argument Se o CPF n�o seguir o formato especificado ou for inv�lido.
     */
    void setCPF(string);

    /**
     * @brief Retorna o valor do CPF.
     * @return CPF.
     */
    string getCPF() const;
};

inline string CPF::getCPF() const
{
    return valor;
}

/**
 * @brief Representa uma data no sistema.
 *
 * Regras de formato:
 *
 * - A data deve seguir o formato DD-MM-AAAA, onde DD � o dia (00 a 31), MM � o m�s (01 a 12) e AAAA � o ano (2000 a 2100).
 * - Leva em considera��o anos bissextos.
 *
 */
// Classe Data
// 200040979
class Data
{
private:
    int dia, mes, ano;
    bool ehBissexto(int) const;
    void validarDia(int, int) const;
    void validarMes(int) const;
    void validarAno(int) const;
    void validarFormatoData(const std::string&, int&, int&, int&) const;

public:
     /**
     * @brief Construtor padr�o.
     */
    Data();

    /**
     * @brief Construtor que inicializa a data com uma string de entrada.
     * @param data String no formato DD-MM-AAAA.
     */
    explicit Data(const std::string&);

    /**
     * @brief Define a data.
     * @param data String no formato DD-MM-AAAA.
     * @throw invalid_argument Se a data n�o seguir o formato especificado.
     */
    void setData(const std::string&);

    /**
     * @brief Retorna a data no formato DD-MM-AAAA.
     * @return Data.
     */
    std::string getData() const;
};

/**
 * @brief Representa um percentual no sistema.
 *
 * Regras de formato:
 *
 * - O percentual deve estar no intervalo de 0 a 100.
 *
 */
// Classe Percentual
// 200040979
class Percentual
{
private:
    int valor;
    void validarValor(int);
public:
    /**
     * @brief Define o valor do percentual.
     * @param valor Percentual a ser definido, no intervalo de 0 a 100.
     * @throw invalid_argument Se o percentual estiver fora da regra de formato.
     */
    void setValor(int);

     /**
     * @brief Retorna o valor do percentual.
     * @return Percentual.
     */
    int getValor() const;
};

/**
 * @brief Representa um nome no sistema.
 *
 * Regras de formato:
 *
 * - O nome deve ser composto por um ou dois termos;
 * - Cada termo deve ter entre 3 e 10 caracteres,
 * - Cada caractere � uma letra (A-Z, a-z);
 * - Os termos s�o separados por um espa�o em branco;
 * - O primeiro caractere de cada termo � uma letra mai�scula.
 *
 */
// Classe Nome
// 231035105
class Nome
{
private:
    string primeiro_nome;
    string sobrenome;

    void validarTermo(const string& termo) const;

public:

    /**
     * @brief Construtor que inicializa o nome com os termos especificados.
     * @param primeiro Primeiro termo do nome.
     * @param segundo Segundo termo do nome (opcional).
     */
    Nome(const string& primeiro, const string& segundo = "");

    /**
     * @brief Retorna o primeiro nome.
     * @return Primeiro nome.
     */
    string getPrimeiroNome() const;

    /**
     * @brief Retorna o sobrenome.
     * @return Sobrenome.
     */
    string getSobreNome() const;

    /**
     * @brief Valida o nome.
     * @return true Se o nome for v�lido.
     * @return false Se o nome for inv�lido.
     */
    bool validarNome() const;

    /**
     * @brief Define o primeiro nome.
     * @param primeiro Primeiro nome a ser definido.
     */
    void setPrimeiroNome(const string& primeiro);

    /**
     * @brief Define o sobrenome.
     * @param segundo Sobrenome a ser definido.
     */
    void setSobreNome(const string& segundo);
};

/**
     * @brief Representa um setor no sistema.
     *
     * O setor deve ser um dos seguintes valores: "Agricultura", "Constru��o civil", "Energia", "Finan�as", "Imobili�rio",
     * "Papel e celulose", "Pecu�ria", "Qu�mica e petroqu�mica", "Metalurgia e siderurgia", "Minera��o".
     *
     */
// Classe Setor
// 231035105
class Setor
{
private:
    string setorNome;
    const static unordered_set<string> setoresValidos;
public:
    /**
     * @brief Construtor que inicializa o setor com o nome especificado.
     * @param setor Nome do setor.
     * @throw invalid_argument Se o setor n�o for um dos valores permitidos.
     */
    Setor(const string& setor);

    /**
     * @brief Retorna o nome do setor.
     * @return Nome do setor.
     */
    string getSetorNome() const;

     /**
     * @brief Define o nome do setor.
     * @param setor Nome do setor.
     * @throw invalid_argument Se o setor n�o for um dos valores permitidos.
     */
    void setSetorNome(const string& setor);

    /**
     * @brief Valida o setor.
     * @throw invalid_argument Se o setor n�o for um dos valores permitidos.
     */
    void validarSetor() const;
};

#endif // DOMAINS_H_INCLUDED
