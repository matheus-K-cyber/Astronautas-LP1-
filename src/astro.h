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
        // Criador:
        Astronauta(std::string cpf, std::string nome, int idade);
        //Observadores:
        std::string getcpf();
        std::string getnome();
        int getidade();
        bool vive();
        bool acessavel();
        // Modificadores:
        void embarcar(); // Vivo e indisponivel
        void desembarcar(); // Se estiver vivo, fica disponível
        void morrer(); // Fica morto e indisponivel, mas ainda cadastrado
};

#endif