#ifndef ACTINT2_EQUIPO_01_PRIM_SALGORITHM_H
#define ACTINT2_EQUIPO_01_PRIM_SALGORITHM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <queue>  // Incluimos la biblioteca para la cola de prioridad

using namespace std;

void optimizeCabling(int numColonias, const vector<vector<int>>& adjacencyMatrix) {
    // Vector que almacena el nodo padre de cada colonia en el árbol de expansión mínima
    vector<int> parent(numColonias, -1);
    // Vector que almacena la clave (distancia mínima) de cada colonia
    vector<int> key(numColonias, INT_MAX);
    // Vector que indica si una colonia está incluida en el árbol de expansión mínima
    vector<bool> inMST(numColonias, false);

    // Usamos una cola de prioridad (heap) para almacenar las claves y nodos
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Inicializamos el primer nodo como inicio del algoritmo
    key[0] = 0;
    pq.push({0, 0});  // La primera entrada es la clave, la segunda es el nodo

    // Bucle principal del algoritmo
    while (!pq.empty()) {
        int u = pq.top().second;  // Extraemos el nodo con la clave mínima
        pq.pop();

        inMST[u] = true;

        // Actualizamos las claves de los nodos adyacentes que aún no están incluidos en el árbol
        for (int v = 0; v < numColonias; ++v) {
            if (adjacencyMatrix[u][v] && !inMST[v] && adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjacencyMatrix[u][v];
                pq.push({key[v], v});  // Agregamos el nuevo nodo a la cola de prioridad
            }
        }
    }

    // Imprimimos la forma óptima de cablear con fibra óptica
    cout << "Forma óptima de cablear con fibra óptica:\n";
    for (int i = 1; i < numColonias; ++i) {
        char coloniaOrigen = 'A' + parent[i];
        char coloniaDestino = 'A' + i;
        cout << "Colonia " << coloniaOrigen << " -- Colonia " << coloniaDestino << "  Distancia: " << adjacencyMatrix[i][parent[i]] << " km\n";
    }
}



#endif //ACTINT2_EQUIPO_01_PRIM_SALGORITHM_H
