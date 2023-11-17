#ifndef CITYNETWORK_H_
#define CITYNETWORK_H_

#include <vector>
#include <limits>
#include <queue>

using namespace std;

// Class CityNetwork
class CityNetwork
{
private:
    int numColonies;
    vector<vector<int>> transmissionCapacity;

public:
    CityNetwork(int numColonies)
    {
        this->numColonies = numColonies;
        transmissionCapacity.resize(numColonies, vector<int>(numColonies, 0));
    }

    void addConnection(int colonyA, int colonyB, int capacity)
    {
        transmissionCapacity[colonyA][colonyB] = capacity;
    }

    int obtainMaxFlow(int colonyA, int colonyB)
    {
        vector<vector<int>> flow(numColonies, vector<int>(numColonies, 0));

        int maxFlow = 0;

        while (true)
        {
            vector<int> parent(numColonies, -1);
            queue<pair<int, int>> q;
            q.push({colonyA, INT_MAX});

            while (!q.empty())
            {
                int current = q.front().first;
                int minCapacity = q.front().second;
                q.pop();

                for (int i = 0; i < numColonies; i++)
                {
                    if (parent[i] == -1 && transmissionCapacity[current][i] - flow[current][i] > 0)
                    {
                        parent[i] = current;
                        int currentCapacity = min(minCapacity, transmissionCapacity[current][i] - flow[current][i]);
                        if (i == colonyB)
                        {
                            maxFlow += currentCapacity;
                            int v = i;
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