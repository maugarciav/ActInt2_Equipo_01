// ====================================================
// File: tsp.h
// Author: Azul Rosales
// Description : Se implementa el algoritmo de Vecino Más Cercano para encontrar la ruta más corta para 
// visitar todas las colonias (regresando al origen).
// Fecha: 16 de noviembre de 2023
// ====================================================

#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

#ifndef ACTINT2_EQUIPO_01_TSP_H
#define ACTINT2_EQUIPO_01_TSP_H

using namespace std;

// Función para encontrar el vecino más cercano no visitado
int encontrarVecinoMasCercano(int ciudadActual, vector<bool>& visitado, vector<vector<int>>& grafo) {
    int mejorVecino = -1;
    int menorDistancia = INT_MAX;

    for (int i = 0; i < visitado.size(); ++i) {
        if (!visitado[i] && grafo[ciudadActual][i] < menorDistancia) {
            mejorVecino = i;
            menorDistancia = grafo[ciudadActual][i];
        }
    }

    return mejorVecino;
}

// Función para calcular la ruta más corta y el costo utilizando el algoritmo del vecino más cercano
// Complejidad de tiempo: O(n2)
pair<vector<int>, int> vecinoMasCercano(int n, vector<vector<int>>& grafo) {
    vector<bool> visitado(n, false);
    vector<int> ruta;
    int ciudadActual = 0; // Comenzar desde la primera colonia

    visitado[ciudadActual] = true;
    ruta.push_back(ciudadActual);

    int costoTotal = 0;

    for (int i = 1; i < n; ++i) {
        int vecino = encontrarVecinoMasCercano(ciudadActual, visitado, grafo);
        visitado[vecino] = true;
        ruta.push_back(vecino);
        costoTotal += grafo[ciudadActual][vecino];
        ciudadActual = vecino;
    }

    // Regresar a la colonia origen
    ruta.push_back(ruta[0]);
    costoTotal += grafo[ciudadActual][ruta[0]];

    return make_pair(ruta, costoTotal);
}

#endif // ACTINT2_EQUIPO_01_TSP_H
