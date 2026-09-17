#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
    private:
        std::string cpf;
        std::string nome;
        int idade;
        bool vivo;
        bool disponivel;

    public:
        //Criador:
        Astronauta(std::string cpf, std::string nome, int idade);
        //Observadores:
        std::string getCpf();
        std::string getNome();
        int getIdade();
        bool vive();
        bool acessavel();
        //Modificadores
        void embarcar(); // vivo e indisponivel
        void desembarcar(); // volta a ficar disponivel, se estiver vivo
        void morrer(); // fica morto e indisponivel, mas ainda cadastrado
};

#endif