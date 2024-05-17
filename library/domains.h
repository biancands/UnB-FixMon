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

//231013583
class Dinheiro {
private:
    static constexpr double LIMITE = 1000000.00;
    double valor;
    void validar(double);
public:
    void setValor(double);
    double getValor() const;
};

inline double Dinheiro::getValor() const{
    return valor;
}

//231013583
class Senha {
private:
    string valor;
    void validar(const string&);
public:
    void setValor(const string&);
    string getValor() const;
};

inline string Senha::getValor() const{
    return valor;
}

//Parra - 211020956
class Codigo{
    private:
        string codigo;
        virtual void validar(string codigo) const = 0;
    public:
        void setCodigo(string);
        inline string getCodigo(){return codigo;}
};

//Parra - 211020956
class CodigoPagamento : public Codigo{
    private:
        void validar(string) const override;
};


//Parra - 211020956
class CodigoTitulo : public Codigo{
    protected:
        void validar(string) const override;
    public:
        const vector<string> listaTitulos = {"CDB","CRA","CRI",
"LCA","LCI","DEB"};
};

//222014142
class Estado{
private:
    string valor;
    void validar(string);
public:
    void setEstado(string);
    string getEstado() const;
};

inline string Estado::getEstado() const{
    return valor;
}

//222014142
class CPF{
private:
    string valor;
    void validar(string);
public:
    void setCPF(string);
    string getCPF() const;
};

inline string CPF::getCPF() const{
    return valor;
}

//200040979
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


//200040979
class Percentual {
private:
    int valor;
    void validarValor(int);
public:
    void setValor(int);
    int getValor() const;
};

//231035105
class Nome{
private:
    string primeiro_nome;
    string sobrenome;

    void validarTermo(const string& termo) const;

public:
    Nome(const string & primeiro, const string& segundo = "");
    string getPrimeiroNome()const;
    string getSobreNome()const;
    bool validarNome() const;

    void setPrimeiroNome(const string& primeiro);
    void setSobreNome(const string& segundo);
};



//231035105
class Setor{
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
