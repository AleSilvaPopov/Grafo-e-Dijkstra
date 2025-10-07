#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "funcao.h"

using namespace std;

int main(){

    abrirArq();
    grafo Dgrafo = lerDistancia();
    fecharArq();
    int menu;
    bool sair = false;
    Resultado R;
    vertice V;

    while(!sair){
        cout << "\nMenu\n" << "1-Distancia entre Estados\n" << "2-Fechar programa\n";
        cin >> menu;
        switch (menu)
        {
        case 1:
            V = lervertices();
            R = dijkstra(Dgrafo,V);
            cout << "Caminho: ";
            for(int i = 0; i < R.caminho.size();i++){
                cout << R.caminho[i] << "=>";
            }
            cout << "Custo minimo = " << R.distancia[Dgrafo.mapaIndices.at(V.final)];
            break;
        case 2:
            cout << "Encerrando o Programa.\n";
            sair = true;
            break;
        
        default:
            cout << "Opção inválida.\n";
            break;
        }
    }
    system("pause");
    return 0;
}