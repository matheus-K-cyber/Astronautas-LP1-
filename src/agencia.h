#ifndef VOO_H
#define VOO_H

#include <vector>
#include <string>

class Agencia { //constituído apenas de modificadores devido ser a responsável pelas "ordens"
    private:
        std::vector<Astronauta> astronautas;
        std::vector<Voo> voos;
        int buscarAstronauta(std::string cpf); // posicao no vector, ou -1
        int buscarVoo(int codigo); // posicao no vector, ou -1

    public:
        void cadastrarAstronauta(std::string cpf, std::string nome, int idade);
        void cadastrarVoo(int codigo);
        void adicionarAstronauta(std::string cpf, int codigo);
        void removerAstronauta(std::string cpf, int codigo);
        void lancarVoo(int codigo);
        void explodirVoo(int codigo);
        void finalizarVoo(int codigo);
        void listarVoos();
        void listarMortos();
};

#endif