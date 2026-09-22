#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>

class Voo {
    private:
        int countA;
        int codigo;
        std::string estado;
        std::vector<std::string> cpfs;

    public:
        Voo(int codigo); //Criador
        // Observadores:
        int getCodigo();
        std::string getEstado();
        int getAstroCount();
        std::string getcpf(int posicao);
        bool temAstro(std::string cpf);
        // Modificadores:
        void addAstro(std::string cpf);
        bool removeAstro(std::string cpf); // False se o CPF nao estava no voo
        void lancar();
        void explodir();
        void finalizar();
};

#endif