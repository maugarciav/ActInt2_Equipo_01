// main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include "Prim’sAlgorithm.h"

using namespace std;

int main() {
    // Nombre de archivos de entrada
    string input1 = "input1.txt";
    string input2 = "input2.txt";
    string input3 = "input3.txt";

    // Abrir el archivo de entrada
    ifstream inputFile(input3);
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo de entrada.\n";
        return 1;
    }

    // Número de colonias (nodos) en el grafo
    int numColonias;
    inputFile >> numColonias;

    // Matriz de adyacencia que representa las distancias entre colonias
    vector<vector<int>> adjacencyMatrix(numColonias, vector<int>(numColonias));
    for (int i = 0; i < numColonias; ++i) {
        for (int j = 0; j < numColonias; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    // Llama a la función para optimizar el cableado utilizando el algoritmo de Prim
    optimizeCabling(numColonias, adjacencyMatrix);

    return 0;
}
