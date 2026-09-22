#include "astro.h"
#include <iostream>
#include <string>
#include <vector>

// IMPLEMNTAÇÕES DOS MÉTODOS
// IMPLEMENTAÇÃO DO CRIADOR:
Astronauta::Astronauta(std::string cpf, std::string nome, int idade) : cpf(cpf), nome(nome), idade(idade) {
    vivo = true;
    disponivel = true;
}

// IMPLEMENTAÇÃO DOS OBSERVADORES:
std::string Astronauta::getcpf() {
    return cpf;
}

std::string Astronauta::getnome() {
    return nome;
}

int Astronauta::getidade() {
    return idade;
}

bool Astronauta::vive() {
    if(vivo) {
    return vivo = true;
    } else {
        return false;
    }
}

bool Astronauta::acessavel() {
    if(disponivel) {
    return disponivel = true;
    } else {
        return false;
    }
}

// IMPLEMENTAÇÃO DOS MODIFICADORES:
void Astronauta::embarcar() {
    disponivel = false;
}

void Astronauta::desembarcar() {
    if(vive) {
        disponivel = true;
    } else {
        morrer();
    }
}

void Astronauta::morrer() {
    vivo = false;
    disponivel = false;
}