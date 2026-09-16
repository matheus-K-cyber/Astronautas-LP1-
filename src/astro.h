#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

using namespace std;

class Astronauta {
private:
string cpf;
string nome;
int idade;
bool vivo;
bool disponivel;

public:
Astronauta(string cpf, string nome, int idade);
string getCpf();
string getNome();
int getIdade();
bool estaVivo();
bool estaDisponivel();
void embarcar(); // fica indisponivel
void desembarcar(); // volta a ficar disponivel, se estiver vivo
void morrer(); // fica morto e indisponivel
};

#endif