#include "agencia.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.
// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

int main() {
    Agencia agencia;                // TODO: criar a Agencia aqui, por exemplo:  Agencia agencia;
    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;

            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos

            agencia.cadastrarAstronauta(cpf, nome, idade);

        } else if (comando == "CADASTRAR_VOO") {
            int codigo;

            cin >> codigo;

            agencia.cadastrarVoo(codigo);

        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;

            agencia.adicionarAstronauta(cpf, codigo);

        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;
            
            agencia.removerAstronauta(cpf, codigo);

        } else if (comando == "LANCAR_VOO") {
            int codigo;

            cin >> codigo;
            
            agencia.lancarVoo(codigo);

        } else if (comando == "EXPLODIR_VOO") {
            int codigo;

            cin >> codigo;

            agencia.explodirVoo(codigo);

        } else if (comando == "FINALIZAR_VOO") {
            int codigo;

            cin >> codigo;
            
            agencia.finalizarVoo(codigo);

        } else if (comando == "LISTAR_VOOS") {
            cout << "LISTA DE VOOS" << endl;

            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            cout << "ASTRONAUTAS MORTOS" << endl;
            
            agencia.listarMortos();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
