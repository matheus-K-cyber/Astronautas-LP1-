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
    return vivo; 
}

bool Astronauta::acessavel() {
    return disponivel;
}

// IMPLEMENTAÇÃO DOS MODIFICADORES:
void Astronauta::embarcar() {
    disponivel = false;
}

void Astronauta::desembarcar() {
    if(vivo) {
        disponivel = true;
    }
}

void Astronauta::morrer() {
    vivo = false;
    disponivel = false;
}