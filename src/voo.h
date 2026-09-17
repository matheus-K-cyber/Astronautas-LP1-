#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>

class Voo {
    private:
        int codigo;
        std::string estado;
        std::vector<std::string> cpfs;

    public:
        Voo(int codigo); //Criador
        //Observadores
        int getCodigo();
        std::string getEstado();
        int getQuantidadeAstronautas();
        std::string getCpf(int posicao);
        bool temAstronauta(std::string cpf);
        //Modificador
        void adicionarAstronauta(std::string cpf);
        bool removerAstronauta(std::string cpf); // false se o CPF nao estava no voo e observador
        void lancar();
        void explodir();
        void finalizar();
};

#endif