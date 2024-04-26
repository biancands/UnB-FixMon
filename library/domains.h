#ifndef DOMAINS_H_INCLUDED
#define DOMAINS_H_INCLUDED
#include <string>
#include <stdexcept>
#include <unordered_set>

//231035105
class Nome{
private:
    std::string primeiro_nome;
    std::string sobrenome;

    void validarTermo(const std::string& termo) const;

public:
    Nome(const std::string & primeiro, const std::string& segundo = "");
    std::string getPrimeiroNome()const;
    std::string getSobreNome()const;
    bool validarNome() const;

    void setPrimeiroNome(const std::string& primeiro);
    void setSobreNome(const std::string& segundo);
};



//231035105
class Setor{
private:
    std::string setorNome;
    const static std::unordered_set<std::string> setoresValidos; 
public:
    Setor(const std::string& setor); 
    std::string getSetorNome() const;
    void setSetorNome(const std::string& setor);
    void validarSetor() const;
};


#endif // DOMAINS_H_INCLUDED
