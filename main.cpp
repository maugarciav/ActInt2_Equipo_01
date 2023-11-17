// ========================================================
// Archivo: main.cpp
// Autores: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Fecha: Viernes, 17 de noviembre del 2023
// ========================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "DijkstraAlgorithm.h"
#include "ClosestCentral.h"
#include "CityNetwork.h"
#include "tsp.h"

using namespace std;

int main()
{

    // Nombre de archivos de entrada
    string input1 = "input1.txt";
    string input2 = "input2.txt";
    string input3 = "input3.txt";

    // Abrir el archivo de entrada
    ifstream inputFile(input1);
    if (!inputFile.is_open())
    {
        cerr << "Error al abrir el archivo de entrada.\n";
        return 1;
    }

    // Número de colonias en el grafo
    int numColonias;
    inputFile >> numColonias;

    // Matriz de adyacencia que representa las distancias entre colonias
    vector<vector<int>> adjacencyMatrix(numColonias, vector<int>(numColonias));
    for (int i = 0; i < numColonias; ++i)
    {
        for (int j = 0; j < numColonias; ++j)
        {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    // Lee la segunda matriz (capacidades máximas de flujo de datos entre colonias)
    vector<vector<int>> flowMatrix(numColonias, vector<int>(numColonias));
    for (int i = 0; i < numColonias; ++i)
    {
        for (int j = 0; j < numColonias; ++j)
        {
            inputFile >> flowMatrix[i][j];
        }
    }

    // Genera el arreglo de coordenadas de las centrales existentes
    vector<pair<int, int>> existingCentrals(numColonias);
    for (int i = 0; i < numColonias; ++i)
    {
        int x, y;
        char par1, comma, par2;
        inputFile >> par1 >> x >> comma >> y >> par2;
        existingCentrals[i] = {x, y};
    }

    // Lee las coordenadas de la nueva central
    int newCentralX, newCentralY;
    char par1, comma;
    inputFile >> par1 >> newCentralX >> comma >> newCentralY;

    // Crear un objeto de la clase CityNetwork
    CityNetwork cityNetwork(numColonias);

    // Agregar las conexiones y capacidades de transmisión
    for (int i = 0; i < numColonias; ++i)
    {
        for (int j = 0; j < numColonias; ++j)
        {
            cityNetwork.addConnection(i, j, flowMatrix[i][j]);
        }
    }

    /*Part1*/
    cout << "Parte 1" << endl;
    printAllPaths(numColonias, adjacencyMatrix);
    cout << endl;
    
    /*Part2*/
    cout << "Parte 2" << endl;
    pair<vector<int>, int> ruta = vecinoMasCercano(numColonias, adjacencyMatrix);
    cout << "Ruta más corta: ";
    for (int i : ruta.first) {
        cout << char('A' + i) << " ";
    }
    cout << "\nCosto total de la ruta: " << ruta.second << " km" << endl;

    /*Part3*/
    cout << "Parte 3" << endl;
    int maxFlow = cityNetwork.obtainMaxFlow(0, 1);
    cout << "Flujo maximo: " << maxFlow << endl;
    cout << endl;

    /*Part 4*/
    cout << "Parte 4" << endl;
    findClosestCentral(newCentralX, newCentralY, existingCentrals);
    cout << endl;

    return 0;
}
