#include <vector>
#include <string>
#include <map>

using namespace std;

struct grafo {
    vector<vector<int>> matrizAdjacencia;
    vector<string> nomesVertices;
    map<string, int> mapaIndices;
};

struct vertice{
    string inicial;
    string final;
};

struct Resultado{
    vector<string> caminho;
    vector<int> distancia;
};

void abrirArq();
grafo lerDistancia();
void fecharArq();
vertice lervertices();
Resultado dijkstra(grafo Dgrafo,vertice v);