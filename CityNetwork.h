// ====================================================
// Archivo: CityNetwork.h
// Autor: José Emiliano Riosmena Castañón - A01704245
// Descripción: Se implementa el algoritmo de
//              Ford-Fulkerson para encontrar el
//              flujo máximo entre dos colonias
// Fecha: Viernes, 17 de noviembre de 2023
// ====================================================

#ifndef CITYNETWORK_H_
#define CITYNETWORK_H_

#include <vector>
#include <limits>
#include <queue>

using namespace std;

// Class CityNetwork
class CityNetwork
{
    // Attributes
private:
    int numColonies;
    vector<vector<int>> transmissionCapacity;

    // Methods
public:
    // Constructor
    CityNetwork(int numColonies)
    {
        this->numColonies = numColonies;
        // Initialize transmissionCapacity matrix
        transmissionCapacity.resize(numColonies, vector<int>(numColonies, 0));
    }

    // Function to add a connection between two colonies
    void addConnection(int colonyA, int colonyB, int capacity)
    {
        transmissionCapacity[colonyA][colonyB] = capacity;
    }

    // Function to obtain the maximum flow between two colonies
    int obtainMaxFlow(int colonyA, int colonyB)
    {
        vector<vector<int>> flow(numColonies, vector<int>(numColonies, 0));

        int maxFlow = 0;

        while (true)
        {
            // BFS
            vector<int> parent(numColonies, -1);
            queue<pair<int, int>> q;
            q.push({colonyA, INT_MAX});

            // Check if there is a path between colonyA and colonyB
            while (!q.empty())
            {
                // Get the current colony and the minimum capacity
                int current = q.front().first;
                int minCapacity = q.front().second;
                q.pop();

                // Check if the current colony is not colonyB and if it has not been visited
                for (int i = 0; i < numColonies; i++)
                {
                    if (parent[i] == -1 && transmissionCapacity[current][i] - flow[current][i] > 0)
                    {
                        parent[i] = current;
                        // Update the minimum capacity with the minimum between the current minimum capacity and the capacity of the current colony
                        int currentCapacity = min(minCapacity, transmissionCapacity[current][i] - flow[current][i]);

                        // If the current colony is colonyB, update the maximum flow and the flow matrix
                        if (i == colonyB)
                        {
                            maxFlow += currentCapacity;
                            int v = i;
                            // Update the flow matrix
                            while (v != colonyA)
                            {
                                int u = parent[v];
                                flow[u][v] += currentCapacity;
                                flow[v][u] -= currentCapacity;
                                v = u;
                            }
                            break;
                        }
                        q.push({i, currentCapacity});
                    }
                }
            }

            if (parent[colonyB] == -1)
            {
                break;
            }
        }

        return maxFlow;
    }
};

#endif /* CITYNETWORK_H_ */