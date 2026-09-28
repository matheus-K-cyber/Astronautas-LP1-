#include "agencia.h"
#include <iostream>
#include <string>
#include <vector>

// IMPLEMNTAÇÕES DOS MÉTODOS
// IMPLEMENTAÇÃO DOS MODIFICADORES:
int Agencia::buscarAstronauta(std::string cpf) {
    for(int i = 0; i < astronautas.size(); i++) {
        if(astronautas[i].getcpf() == cpf) {
            return i;
        }
    }

    return -1;
}

int Agencia::buscarVoo(int codigo) {
    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getCodigo() == codigo) {
            return i;
        }
    }

    return -1;
}

void Agencia::cadastrarAstronauta(std::string cpf, std::string nome, int idade) {
    Astronauta newA = Astronauta(cpf, nome, idade);
    int test = buscarAstronauta(cpf);

    if(test >= 0) {
        std::cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << std::endl;
    } else if(test == -1) {
        astronautas.push_back(newA);

        std::cout << "OK: astronauta " << cpf << " cadastrado" << std::endl;
    }
}

void Agencia::cadastrarVoo(int codigo) {
    Voo newV = Voo(codigo);
    int test = buscarVoo(codigo);

    if(test >= 0) {
        std::cout << "ERRO: voo " << codigo << " ja cadastrado" << std::endl;
    } else if(test == -1) {
        voos.push_back(newV);

        std::cout << "OK: voo " << codigo << " cadastrado" << std::endl;
    }
}

void Agencia::adicionarAstronauta(std::string cpf, int codigo) {
    int testA = buscarAstronauta(cpf);
    int testV = buscarVoo(codigo);

    astronautas[testA].embarcar();
    voos[testV].addAstro(cpf);

    if(voos[testV].getEstado() != "planejado") {
        std::cout << "ERRO: voo " << codigo << " nao esta planejado" << std::endl;

        removerAstronauta(cpf, codigo);
    } else if(testV == -1){
        std::cout << "ERRO: voo " << codigo << " nao esta cadastrado" << std::endl;

        removerAstronauta(cpf, codigo);
    } else if(voos[testV].temAstro(cpf)) {
        std::cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo  << std::endl;

        removerAstronauta(cpf, codigo);
    } else if(testA == -1) {
        std::cout << "ERRO: astronauta " << cpf << " nao cadastrado" << std::endl;

        removerAstronauta(cpf, codigo);
    } else if(!astronautas[testA].vive()) {
        std::cout << "ERRO: astronauta " << cpf << " esta morto" << std::endl;

        removerAstronauta(cpf, codigo);
    } else {
        std::cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << std::endl;

        if(!astronautas[testA].acessavel()) {
            std::cout << "ERRO: astronauta " << cpf << " esta indisponivel" << std::endl;

            removerAstronauta(cpf, codigo);
        }
    }
}

void Agencia::removerAstronauta(std::string cpf, int codigo) {
    int testA = buscarAstronauta(cpf);
    int testV = buscarVoo(codigo);

    if(testA == -1) {
        std::cout << "ERRO: astronauta " << cpf << " nao cadastrado" << std::endl;
    } else if(voos[testV].getEstado() != "planejado") {
        std::cout << "ERRO: voo " << codigo << " nao esta planejado" << std::endl;
    } else if(testV == -1){
        std::cout << "ERRO: voo " << codigo << " nao esta cadastrado" << std::endl;
    } else if(!voos[testV].removeAstro(cpf)) {
        std::cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << std::endl;
    } else if(voos[testV].removeAstro(cpf)) {
        std::cout << "OK: astronauta " << cpf << " removido do voo " << codigo << std::endl;
    }

    voos[testV].removeAstro(cpf);
}

void Agencia::lancarVoo(int codigo) {
    int testV = buscarVoo(codigo);

    if(voos[testV].getEstado() != "planejado") {
        std::cout << "ERRO: voo " << codigo << " nao esta planejado" << std::endl;
    } else if(testV == -1){
        std::cout << "ERRO: voo " << codigo << " nao esta cadastrado" << std::endl;
    } else if(voos[testV].getAstroCount() == 0){
        std::cout << "ERRO: voo " << codigo << " nao possui astronautas" << std::endl;
    } 
    
    for(int i = 0; i < astronautas.size(); i++) {
        if(!astronautas[i].vive()) {
            std::cout << "ERRO: astronauta " << astronautas[i].getcpf() << " esta morto" << std::endl;

            break;
        } else if(!astronautas[i].acessavel()) {
            std::cout << "ERRO: astronauta " << astronautas[i].getcpf() << " esta indisponivel" << std::endl;

            break;
        }
    }
    
    if(voos[testV].getCodigo() == codigo) {
        voos[testV].lancar();

        std::cout << "OK: voo " << codigo << " lancado" << std::endl;
    }
}

void Agencia::explodirVoo(int codigo) {
    int testV = buscarVoo(codigo);
    
    if(voos[testV].getEstado() != "planejado") {
        std::cout << "ERRO: voo " << codigo << " nao esta planejado" << std::endl;
    } else if(testV == -1){
        std::cout << "ERRO: voo " << codigo << " nao esta cadastrado" << std::endl;
    } else if(voos[testV].getCodigo() == codigo) {
        voos[testV].explodir();
        astronautas[testV].morrer();

        std::cout << "OK: voo " << codigo << " explodiu" << std::endl;
    }
}

void Agencia::finalizarVoo(int codigo) {
    int testV = buscarVoo(codigo);
    
    if(voos[testV].getEstado() != "planejado") {
        std::cout << "ERRO: voo " << codigo << " nao esta planejado" << std::endl;
    } else if(testV == -1){
        std::cout << "ERRO: voo " << codigo << " nao esta cadastrado" << std::endl;
    } else if(voos[testV].getCodigo() == codigo) {
        voos[testV].finalizar();
    } 
    
    if(voos[testV].getEstado() == "finalizado com explosao") {
            std::cout << "OK: voo " << codigo << " explodiu" << std::endl;
    } else {
            std::cout << "OK: voo " << codigo << " finalizado com sucesso" << std::endl;
    }
}


void Agencia::listarVoos() {
    std::cout << "== planejado ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() != "planejado") {
                std::cout << "(nenhum)" << std::endl;
        } else if(voos[i].getEstado() == "planejado") {
            std::cout << "Voo " << voos[i].getCodigo() << ": ";

            if(voos[i].getAstroCount() == 0) {
                std::cout << "sem astronautas" << std::endl;
            } else {
            std::cout << astronautas[i].getcpf() << " " << astronautas[i].getnome();

                if(i + 1 < voos.size() && voos[i + 1].getEstado() == "planejado" && voos[i + 1].getCodigo() == voos[i].getCodigo()) {
                    std::cout << ", ";
                } else {
                    std::cout << std::endl;
                }
            }
        }
    }

    std::cout << "== em curso ==" << std::endl;

    std::cout << "(nenhum)" << std::endl;

    std::cout << "== finalizado com sucesso ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() != "finalizado com sucesso") {
            std::cout << "(nenhum)";
        } else if(voos[i].getEstado() == "finalizado com sucesso" ) {
            std::cout << "Voo " << voos[i].getCodigo() << ": " << voos[i].getcpf(i) << " " << astronautas[i].getnome();

            if(voos[i + 1].getEstado() == "finalizado com sucesso" && voos[i + 1].getCodigo() == voos[i].getCodigo()) {
                std::cout << ", " << voos[i].getcpf(i) << " " << astronautas[i].getnome();
            }

            std::cout << std::endl;
        }
    }

    std::cout << "\n== finalizado com explosao ==" << std::endl;

    for(int i = 0; i < voos.size(); i++) {
        if(voos[i].getEstado() != "finalizado com explosao") {
            std::cout << "(nenhum)" << std::endl;
        } else if(voos[i].getEstado() == "finalizado com explosao") {
            std::cout << "Voo " << voos[i].getCodigo() << ": " << voos[i].getcpf(i) << " " << astronautas[i].getnome();

            if(voos[i + 1].getEstado() == "finalizado com explosao" && voos[i + 1].getCodigo() == voos[i].getCodigo()) {
                std::cout << ", " << voos[i].getcpf(i) << " " << astronautas[i].getnome();
            }
        }
    }
}

void Agencia::listarMortos() {
    for(int i = 0; i < astronautas.size(); i++) {
        if(voos[i].getEstado() != "finalizado com explosão") {
            std::cout << "(nenhum)" << std::endl;
        } else if(voos[i].getEstado() == "finalizado com explosão") {
            std::cout << voos[i].getcpf(i) << " " << astronautas[i].getnome() << " - voos:" 
            << voos[i].getCodigo() << std::endl;
            
            if(voos[i + 1].getEstado() == "finalizado com explosao") {
                std::cout << voos[i].getcpf(i) << " " << astronautas[i].getnome() << " - voos:" 
            << voos[i].getCodigo() << std::endl;
            }
        }
    }
}