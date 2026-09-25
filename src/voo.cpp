#include "voo.h"
#include <iostream>
#include <string>
#include <vector>

// IMPLEMNTAÇÕES DOS MÉTODOS
// IMPLEMENTAÇÃO DO CRIADOR:
Voo::Voo(int codigo) : codigo(codigo) {
    estado = "planejado";
    countA = 0;
}

// IMPLEMENTAÇÃO DOS OBSERVADORES:
int Voo::getCodigo() {
    return codigo;
}

std::string Voo::getEstado() {
    return estado;
}

int Voo::getAstroCount() {
    return countA;
}

std::string Voo::getcpf(int posicao) {
    return cpfs.at(posicao);
}

bool Voo::temAstro(std::string cpf) {
    for(int i = 0; i < cpfs.size(); i++) {
        if(cpfs[i] == cpf) {
            return true;
        }
    }

    return false;
}

// IMPLEMENTAÇÃO DOS MODIFICADORES:
void Voo::addAstro(std::string cpf) {
    cpfs.push_back(cpf);
    countA++;
}

bool Voo::removeAstro(std::string cpf) {
    for(int i = 0; i < cpfs.size(); i++) {
        if(cpfs[i] == cpf) {
            cpfs.erase(cpfs.begin() + i);
            countA--;
            return true;
        }
    }

    return false;
}

void Voo::lancar() {
    estado = "em curso";
}

void Voo::explodir() {
    estado = "ex";
}

void Voo::finalizar() {
    if(estado == "ex") {
        estado = "finalizado com explosao";
    } else {
        estado = "finalizado com sucesso";
    }
}