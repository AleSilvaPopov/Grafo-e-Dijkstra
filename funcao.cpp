#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <limits>
#include <algorithm>
#include "funcao.h"


//comentarios para o Peu, lembre de apagar antes de enviar 

using namespace std;

ifstream distancia; // tem q excluir esse carai depois e adicionar la em baixo é que o meu não tava rodando se essa merda não fosse global 
void ListaEstados() {
    cout << "Estados:\n";
    cout << "AC - Acre\t\tAL - Alagoas\t\tAP - Amapá\n";
    cout << "AM - Amazonas\t\tBA - Bahia\t\tCE - Ceará\n";
    cout << "DF - Distrito Federal\tES - Espírito Santo\tGO - Goiás\n";
    cout << "MA - Maranhão\t\tMT - Mato Grosso\tMS - Mato Grosso do Sul\n";
    cout << "MG - Minas Gerais\tPA - Pará\t\tPB - Paraíba\n";
    cout << "PR - Paraná\t\tPE - Pernambuco\t\tPI - Piauí\n";
    cout << "RJ - Rio de Janeiro\tRN - Rio Grande do Norte\tRS - Rio Grande do Sul\n";
    cout << "RO - Rondônia\t\tRR - Roraima\t\tSC - Santa Catarina\n";
    cout << "SP - São Paulo\t\tSE - Sergipe\t\tTO - Tocantins\n";
}

//Só pra abrir o arquivo
void abrirArq(){
    distancia.open("distancia.txt");

    if(!distancia.is_open()){
        cout << "erro ao abrir arquivo";
        return;
    }
}

//Só pra fechar o arquivo e não ter b.o depois
void fecharArq(){
    distancia.close();
}

//aqui começa a desgraceira do carai
grafo lerDistancia(){

    grafo Dgrafo;
    string linha;


    //ler vertices exp. AC = 0, AL = 1 por ai vai;
    if(getline(distancia, linha)){ // le a primeira linha AC, AL...
        stringstream ss(linha); // separar as paradas
        string nome; getline(ss, nome, ','); // ignora o que não serve pra nada exp: ,

        int indice = 0; // da nome aos bois
        while (getline(ss, nome, ',')) {
            if (!nome.empty() && nome.back() == '\r') { // não sei o que faz tava dando erro a IA mandou colocar igual a linha de baixo
                nome.pop_back(); // linha de baixo
            }
            Dgrafo.nomesVertices.push_back(nome); //adiciona o nome do estado ao final da lista
            Dgrafo.mapaIndices[nome] = indice++; // Mudando de AL, AC pra indice da matriz
        }
    }

    int numVertice = Dgrafo.nomesVertices.size(); //tamanho da matriz
    const int inf = numeric_limits<int>::max(); /*quando não tem contato tlgd vou colocar infinito, mas 
    se tu quiser colocar -1 ou qualquer outra bosta é só apagar essa linha e mudar o inf la em baixo pra 
    essa bosta nao esquece de apagar a biiblioteca tambem <limits>*/ 

    Dgrafo.matrizAdjacencia.assign(numVertice, vector<int>(numVertice));//cria a matriz

    int linhaAtual = 0; // faz a contagem de linhas

    //preenche a matriz
    while(getline(distancia, linha)){ //ta lendo o arquivo
        stringstream ss(linha);// serve pra separar as informações lidas na linha 
        string valor;

        getline(ss, valor, ','); // para de ler assim q vê uma virgula

        for (int colAtual = 0; colAtual < numVertice; ++colAtual) { //so lê ai
            getline(ss, valor, ',');// para de ler assim q vê uma virgula
            
            if (valor == "inf") {
                Dgrafo.matrizAdjacencia[linhaAtual][colAtual] = inf; //aqui que deve mudar se for mudar o infinito pra -1 ou alguma outra coisa
            } else {
                Dgrafo.matrizAdjacencia[linhaAtual][colAtual] = stoi(valor);//preenchendo e stoi muda de string pra int
            }
        }
        linhaAtual++;//mudando a linha
    }

     fecharArq();
    return Dgrafo; //retorna a matriz pra tu usar
}

vertice lervertices(){
    vertice v;
    ListaEstados();
    cout << "Informe o Estado inicial: ";
    cin >> v.inicial;
    ListaEstados();
    cout << "Informe o Estado final: ";
    cin >> v.final;

    return v;
}

Resultado dijkstra(grafo Dgrafo,vertice v){
    Resultado Cam;
    int n = Dgrafo.nomesVertices.size();
    int menor,peso;
    vector<string> caminhoFim_Inicio;

    //inicializa os vetores do caminho e nodos visitados
    Cam.distancia.assign(n,numeric_limits<int>::max());
    vector<bool>Visitado(n,false);
    vector<int> anterior(n,-1);
    
    int inicio = Dgrafo.mapaIndices.at(v.inicial);
    int fim = Dgrafo.mapaIndices.at(v.final);
    Cam.distancia[inicio] = 0; // No de inicio escolhido
    
   //Loop principal do algoritmo
    for(int i = 0;i < n - 1;i++){
        int u = -1;
        menor = numeric_limits<int>::max();

        // Encontra o vertice não visitado com menor distancia
        for(int j = 0;j < n;j++){
            if(!Visitado[j] && Cam.distancia[j] < menor){
                menor = Cam.distancia[j];
                u = j;
            }
        }
        if(u==-1) break; //Não tem como alcancar nenhum vértice

        Visitado[u] = true; //Marca o Vertice atual como visitado

        // Ve os vertices vizinhos;
        for(int v = 0; v < n; ++v){
            peso = Dgrafo.matrizAdjacencia[u][v];
            if (!Visitado[v] && peso != numeric_limits<int>::max() && Cam.distancia[u] + peso < Cam.distancia[v]){
                Cam.distancia[v] = Cam.distancia[u] + peso;
                anterior[v] = u;
            }
        }
    }
    //Arruma o caminho minimo
    for(int k = fim;k != -1; k = anterior[k]){
        caminhoFim_Inicio.push_back(Dgrafo.nomesVertices[k]);
    } //Da o caminho porem invertido

    //Arruma a ordem invertendo o vetor
    reverse(caminhoFim_Inicio.begin(),caminhoFim_Inicio.end());
    Cam.caminho = caminhoFim_Inicio;
    return Cam;
}