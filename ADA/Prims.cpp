#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int findMinKey(vector<int> key, vector<bool> mstSet, int V) {
    int minValue = INT_MAX;
    int minIndex=0;

    for (int i = 0; i < V; i++) {
        if (mstSet[i] == false && key[i] < minValue) {
            minValue = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printMST(vector<int> parent, vector<vector<int>> graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

void primMST(vector<vector<int>> graph, int V) {
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, graph.size());

    return 0;
}