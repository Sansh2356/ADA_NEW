#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = 10e9;

vector<vector<pair<int, int>>> graph;
vector<int> dist(graph.size(),INF);
vector<int> parent(graph.size(),-1);

void dijkstra(int src) {
    
   
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (dist[u] == INF) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}

void printPath(int dest) {
    if (parent[dest] == -1) {
        cout << dest << " ";
        return;
    }

    printPath(parent[dest]);
    cout << dest << " ";
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int src;
    cin >> src;

    dijkstra(src);

    for (int i = 0; i < dist.size(); i++) {
        if (i == src) continue;

        cout << "Shortest distance from " << src << " to " << i << ": " << dist[i] << endl;
        cout << "Path: ";
        printPath(i);
        cout << endl;
    }

    return 0;
}