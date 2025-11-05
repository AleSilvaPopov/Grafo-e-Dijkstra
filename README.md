# Trabalho de Teoria dos Grafos - Algoritmo de Dijkstra

**Disciplina:** Teoria dos Grafos 
**Docente:** Alexandre Augusto Angelo de Souza 

Este projeto é uma implementação em C++ do algoritmo de Dijkstra, projetado para encontrar o caminho mais curto entre dois estados brasileiros com base em uma matriz de adjacências.

---

## 🎯 Objetivo

O objetivo principal é desenvolver um programa capaz de ler uma topologia de rede (representada por distâncias rodoviárias entre estados) e aplicar o algoritmo de otimização de Dijkstra para determinar o menor caminho e o custo total entre dois vértices (estados) definidos pelo usuário. 

---

## 📋 Especificações do Programa

O programa executa as seguintes etapas:

1.  **Leitura da Topologia:** Realiza a leitura da matriz de adjacências a partir do arquivo `distancia.txt`. 
    * A matriz representa os estados brasileiros. 
    * O valor na célula indica a distância (custo) entre dois estados. 
    * O valor `inf` (infinito) indica que não há uma rodovia direta conectando os estados. 
2.  **Seleção de Vértices:** Solicita que o usuário defina o estado inicial e o estado final.
3.  **Apresentação do Resultado:** Exibe em tela o percurso (sequência de estados) encontrado e o custo total do caminho mínimo. [cite: 12]

---

## 🛠️ Tecnologias Utilizadas

* Linguagem C++ 

---

## 📂 Estrutura dos Arquivos

* `main.cpp`: Contém o loop principal do programa e o menu de interação com o usuário.
* `funcao.h`: Arquivo de cabeçalho que define as `structs` (grafo, vertice, Resultado) e os protótipos das funções.
* `funcao.cpp`: Contém a implementação das funções principais:
    * `lerDistancia`: Lê e processa o arquivo `distancia.txt`.
    * `lervertices`: Captura a entrada do usuário (estado inicial e final).
    * `dijkstra`: Implementação do algoritmo de Dijkstra.
* `distancia.txt`: Arquivo de dados contendo a matriz de adjacências (distâncias entre os estados).

---

## 🚀 Como Compilar e Executar

É necessário ter um compilador C++ (como G++) instalado.

1.  **Pré-requisito:**
    Certifique-se de que o arquivo `distancia.txt` [cite: 1] esteja no mesmo diretório que os arquivos de código-fonte.

2.  **Compile os arquivos:**
    Abra um terminal no diretório do projeto e execute o comando:

    ```bash
    g++ -o dijkstra main.cpp funcao.cpp
    ```

3.  **Execute o programa:**

    ```bash
    ./dijkstra
    ```

4.  **Interaja com o menu:**
    O programa exibirá um menu. Selecione a opção "1" para encontrar a distância entre os estados e siga as instruções, ou "2" para sair.