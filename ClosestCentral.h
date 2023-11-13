// ====================================================
// File: ClosestCentral.h
// Author: Mauricio Garcia Villanueva
// Description : Se implementa el algoritmo de Dijkstra para encontrar la distancia más corta entre la
// ubicación de la nueva central y la central más cercana usando la distancia euclidiana
// Fecha: 12 de noviembre de 2023
// ====================================================
#ifndef ACTINT2_EQUIPO_01_CLOSESTCENTRAL_H
#define ACTINT2_EQUIPO_01_CLOSESTCENTRAL_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * La función findClosestCentral recibe las coordenadas (x, y) de la nueva central y la lista de coordenadas
 * de las centrales existentes. Imprime la cental mas cercana a la nueva central
 *
 *
 * Tiempo de Complejidad = O(n)
 * n = nuemro de centrales
 */
void findClosestCentral(int newCentralX, int newCentralY, const vector<pair<int, int>>& existingCentrals) {
    int closestCentralIndex = -1;
    double minDistance = numeric_limits<double>::infinity();


    // Calculamos la distancia euclidiana entre la nueva central y cada central existente
    /*
     * Distancia= ((x2 - x1)^2 + (y2 - y1)^2)^1/2
     */
    for (int i = 0; i < existingCentrals.size(); ++i) {
        int existingCentralX = existingCentrals[i].first;
        int existingCentralY = existingCentrals[i].second;

        double distance = sqrt(pow(newCentralX - existingCentralX, 2) + pow(newCentralY - existingCentralY, 2));

        if (distance < minDistance) {
            minDistance = distance;
            closestCentralIndex = i;
        }
    }


    cout << "La central mas cerca a [" << newCentralX << "," << newCentralY << "] es [" << existingCentrals[closestCentralIndex].first
         << "," << existingCentrals[closestCentralIndex].second << "] con una distancia de: " << minDistance << endl;

}


#endif //ACTINT2_EQUIPO_01_CLOSESTCENTRAL_H
