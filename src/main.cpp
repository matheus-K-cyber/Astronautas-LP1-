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

            Astronauta test1(cpf, nome, idade);

            if(!test1.vive()) {
            agencia.cadastrarAstronauta(cpf, nome, idade);

            cout << "OK: astronauta " << cpf << " cadastrado" << endl;
            } else {
                cout << "ERRO: astronauta com CPF " << cpf <<" ja cadastrado" << endl;
            }

        } else if (comando == "CADASTRAR_VOO") {
            int codigo;

            cin >> codigo;

            Voo test1(codigo);

            if(test1.getEstado() == "planejado") {
                cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
            } else {
            agencia.cadastrarVoo(codigo);

            cout << "OK: voo " << codigo << " cadastrado" << endl;
            }

        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;

            Voo test2(codigo);
            string retorno = test2.getcpf(codigo);

            if(test2.temAstro(cpf)) {
                cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
            } else if (retorno != cpf) {
                cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            } else {
            
            agencia.adicionarAstronauta(cpf, codigo);

            cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
            }
            // PRECISO DOS COUTS AQUI? OU POSSO DEIXAR PARA AGENCIA E A MAIN APENAS CONVOCA?
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;
            
            agencia.removerAstronauta(cpf, codigo);

            cout << "OK: astronauta " << cpf <<" removido do voo " << codigo << endl;
        } else if (comando == "LANCAR_VOO") {
            int codigo;

            cin >> codigo;
            
            agencia.lancarVoo(codigo);

            cout << "OK: voo " << codigo << " lancado" << endl;
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;

            cin >> codigo;

            agencia.explodirVoo(codigo);

            cout << "OK: voo " << codigo << " explodiu" << endl;
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;

            cin >> codigo;
            
            agencia.finalizarVoo(codigo);

            cout << "OK: voo "  << codigo << " finalizado com sucesso" << endl;
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
