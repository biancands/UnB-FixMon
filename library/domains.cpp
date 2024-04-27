#include "domains.h"
#include <regex>
#include <unordered_set>
#include <cctype>

Nome::Nome(const std::string& primeiro, const std::string& segundo) : primeiro_nome(primeiro), sobrenome(segundo){
    validarTermo(primeiro);
    validarTermo(segundo);
}

std::string Nome::getPrimeiroNome() const{
    return primeiro_nome;
}

std::string Nome::getSobreNome() const{
    return sobrenome;
}

bool Nome::validarNome()const{
    std::regex padrao("^([A-Z][a-z]{2,9})(\\s([A-Z][a-z]{2,9}))?$");
    return std::regex_match(primeiro_nome + ' ' + sobrenome, padrao);

};

void Nome::setPrimeiroNome(const std::string& primeiro){
    validarTermo(primeiro);
    primeiro_nome = primeiro;
}

void Nome::setSobreNome(const std::string& segundo){
    validarTermo(segundo);
    sobrenome = segundo;
}

void Nome::validarTermo(const std::string& termo) const{
    if (termo.empty()){
        throw std::invalid_argument("Não pode ser vazio");
    }

    if (termo.size() < 3 || termo.size() > 10){
        throw std::invalid_argument("O termo deve ter entre 3 e 10 caracteres");
    }

    if (!isupper(termo[0])) {
        throw std::invalid_argument("Todos os caracteres devem ser letras.");
    }
}

const std::unordered_set<std::string>Setor::setoresValidos = {
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

Setor::Setor(const std::string& setor) : setorNome(setor) {
    validarSetor();
}

std::string Setor::getSetorNome() const {
    return setorNome;
};

void Setor::validarSetor() const{
    if (setoresValidos.count(setorNome) == 0){
        throw std::invalid_argument("invalido");
    }
}

void Setor::setSetorNome(const std::string& setor){
    setorNome = setor;
    validarSetor();
}