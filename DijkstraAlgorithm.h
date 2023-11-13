// ====================================================
// File: DijkstraAlgorithm.h
// Author: Mauricio Garcia Villanueva
// Description : Implementación del algoritmo de Dijkstra para encontrar la distancia más corta entre un nodo de inicio
// y todos los demás nodos en un grafo ponderado.
// Fecha: 13 de noviembre de 2023
// ====================================================

#ifndef ACTINT2_EQUIPO_01_DIJKSTRAALGORITHM_H
#define ACTINT2_EQUIPO_01_DIJKSTRAALGORITHM_H

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;


/*
 * Implementación del algoritmo de Dijkstra para encontrar la distancia más corta entre un nodo
 * de inicio y todos los demás nodos en un grafo ponderado.
 *
 *
 * Tiempo de complejidad: O(E * log(V))
 * E: Número de aristas en el grafo
 * V: Número de nodos (colonias) en el grafo
 *
 */
void dijkstra(int start, int numColonias, const vector<vector<int>>& adjacencyMatrix) {
    // Vector para almacenar las distancias mínimas
    vector<int> distance(numColonias, INT_MAX);
    // Vector para almacenar los nodos padres en el camino más corto
    vector<int> parent(numColonias, -1);
    // Cola de prioridad para almacenar las distancias y nodos
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //Distancia inical 0
    distance[start] = 0;
    // Agregamos el nodo de inicio a la cola de prioridad
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;  // Extraemos el nodo con la distancia mínima
        pq.pop();

        //Iteramos sobre todos los nodos adyacentes
        for (int v = 0; v < numColonias; ++v) {
            // Verificamos si hay una conexion entre u y v
            if (adjacencyMatrix[u][v] && distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                // Actualizamos la distancia (si es menor)
                distance[v] = distance[u] + adjacencyMatrix[u][v];
                // Establecemos a u como el padre de v
                parent[v] = u;
                // Agregamos el  nodo a la cola de prioridad
                pq.push({distance[v], v});
            }
        }
    }

    // Imprimimos las distancias mínimas desde el nodo de inicio a todos los demás nodos
    cout << endl;
    for (int i = 0; i < numColonias; ++i) {
        if (i != start) {
            cout << "Colonia " << start + 1 << " a Colonia " << i + 1 << ": " << distance[i] << endl;
        }
    }
}


/*
 * Función para imprimir todas las rutas más cortas desde cada nodo hacia todos los demás nodos
 *
 *
 * Tiempo de complejidad: O(V * (E * log(V)))
 * E: Número de aristas en el grafo
 * V: Número de nodos (colonias) en el grafo
 */
void printAllPaths(int numColonias, const vector<vector<int>>& adjacencyMatrix) {
    for (int i = 0; i < numColonias; ++i) {
        dijkstra(i, numColonias, adjacencyMatrix);
    }
}

#endif //ACTINT2_EQUIPO_01_DIJKSTRAALGORITHM_H
