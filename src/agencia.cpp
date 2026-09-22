#include "agencia.h"
#include <iostream>
#include <string>
#include <vector>

// IMPLEMNTAÇÕES DOS MÉTODOS
// IMPLEMENTAÇÃO DOS MODIFICADORES:
void Agencia::cadastrarAstronauta(std::string cpf, std::string nome, int idade) {
    Astronauta newA = Astronauta(cpf, nome, idade);
    /*int test = buscarAstronauta(cpf);

    if(test == -1) {
        std::cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << std::endl;
    } else {
    astronautas.push_back(newA);
    }*/
    astronautas.push_back(newA);
}

void Agencia::cadastrarVoo(int codigo) {
    Voo newV = Voo(codigo);

    voos.push_back(newV);
}

void Agencia::adicionarAstronauta(std::string cpf, int codigo) {
    for(int i = 0; i < astronautas.size(); i++) {
        if(voos[i].getCodigo() == codigo && !voos[i].temAstro(cpf)) {
            voos[i].addAstro(cpf);
            astronautas[i].embarcar();
            astronautas[i].vive();
        } else {
            
        }
    }
}

void Agencia::removerAstronauta(std::string cpf, int codigo) {
    for(int i = 0; i < astronautas.size(); i++) {
        if(voos[i].getCodigo() == codigo) {
            voos[i].removeAstro(cpf);
            astronautas[i].desembarcar();
        }
    }
}

void Agencia::lancarVoo(int codigo) {
    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getCodigo() == codigo) {
            voos[i].lancar();

        }
    }
}

void Agencia::explodirVoo(int codigo) {
    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getCodigo() == codigo) {
            voos[i].explodir();
            astronautas[i].morrer();
        }
    }
}

void Agencia::finalizarVoo(int codigo) {
    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getCodigo() == codigo) {
            voos[i].finalizar();
        }
    }
}

void Agencia::listarVoos() {
    std::cout << "== planejado ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() == "planejado") {
            std::cout << "voo " << voos[i].getCodigo() << ": " << astronautas[i].getcpf() << " " << astronautas[i].getnome();
            if(voos[i + 1].getEstado() == "planejado") {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;

    std::cout << "== em curso ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() == "em curso") {
            std::cout << "voo " << voos[i].getCodigo() << ": " << astronautas[i].getcpf() << " " << astronautas[i].getnome();
            if(voos[i + 1].getEstado() == "em curso") {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;

    std::cout << "== finalizado com sucesso ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() == "finalizado com sucesso") {
            std::cout << "voo " << voos[i].getCodigo() << ": " << astronautas[i].getcpf() << " " << astronautas[i].getnome();
            if(voos[i + 1].getEstado() == "finalizado com sucesso") {
                std::cout << ", ";
                astronautas[i].desembarcar();
            }
        }
    }
    std::cout << std::endl;

    std::cout << "== finalizado com explosao ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() == "finalizado com explosao") {
            std::cout << "voo " << voos[i].getCodigo() << ": " << astronautas[i].getcpf() << " " << astronautas[i].getnome();
            if(voos[i + 1].getEstado() == "finalizado com explosao") {
                std::cout << "\n";
                astronautas[i].desembarcar();
            }
        }
    }
    std::cout << std::endl;
}

void Agencia::listarMortos() {
    for(int i = 0; i < astronautas.size(); i++) {
        if(voos[i].getEstado() == "finalizado com explosão") {
            std::cout << astronautas[i].getcpf() << " " << astronautas[i].getnome() << " - voos:" << voos[i].getCodigo() << std::endl;
        }
    }
}