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

// Classe Dinheiro
// 231013583
class Dinheiro {
private:
    static constexpr double LIMITE = 1000000.00;
    double valor;
    void validar(double);
public:
    void setValor(double);
    double getValor() const;
};

inline double Dinheiro::getValor() const {
    return valor;
}

// Classe Senha
// 231013583
class Senha {
private:
    string valor;
    void validar(const string&);
public:
    void setValor(const string&);
    string getValor() const;
};

inline string Senha::getValor() const {
    return valor;
}

// Classe Código
// Parra - 211020956
class Codigo {
private:
    string codigo;
    virtual void validar(string codigo) const = 0;
public:
    void setCodigo(string);
    inline string getCodigo() { return codigo; }
};

// Classe Código Pagamento
// Parra - 211020956
class CodigoPagamento : public Codigo {
private:
    void validar(string) const override;
};

// Classe Código Título
// Parra - 211020956
class CodigoTitulo : public Codigo {
protected:
    void validar(string) const override;
public:
    vector<string> listaTitulos = {"CDB", "CRA", "CRI", "LCA", "LCI", "DEB"};
};

// Classe Estado
// 222014142
class Estado {
private:
    string valor;
    void validar(string);
public:
    void setEstado(string);
    string getEstado() const;
};

inline string Estado::getEstado() const {
    return valor;
}

// Classe CPF
// 222014142
class CPF {
private:
    string valor;
    void validar(string);
public:
    void setCPF(string);
    string getCPF() const;
};

inline string CPF::getCPF() const {
    return valor;
}

// Classe Data
// 200040979
class Data {
private:
    int dia, mes, ano;
    bool ehBissexto(int) const;
    void validarDia(int, int) const;
    void validarMes(int) const;
    void validarAno(int) const;
    void validarFormatoData(const std::string&, int&, int&, int&) const;

public:
    Data();
    explicit Data(const std::string&);

    void setData(const std::string&);
    std::string getData() const;
};

// Classe Percentual
// 200040979
class Percentual {
private:
    int valor;
    void validarValor(int);
public:
    void setValor(int);
    int getValor() const;
};

// Classe Nome
// 231035105
class Nome {
private:
    string primeiro_nome;
    string sobrenome;

    void validarTermo(const string& termo) const;

public:
    Nome(const string& primeiro, const string& segundo = "");
    string getPrimeiroNome() const;
    string getSobreNome() const;
    bool validarNome() const;

    void setPrimeiroNome(const string& primeiro);
    void setSobreNome(const string& segundo);
};

// Classe Setor
// 231035105
class Setor {
private:
    string setorNome;
    const static unordered_set<string> setoresValidos;
public:
    Setor(const string& setor);
    string getSetorNome() const;
    void setSetorNome(const string& setor);
    void validarSetor() const;
};

#endif // DOMAINS_H_INCLUDED
