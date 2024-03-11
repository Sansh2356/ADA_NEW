#include <iostream>
#include <vector>
#include <algorithm>
/*
    LIST OF ADA PRACTICALS DONE TILL NOW
    1)prim
    2)kruskal
    3)knapsack
    4)selectionsort,permutation,power
    5)magic square
    6)multi-stage-graph
    7)djikstra
    8)pivotelement
    9)merge and quick
    10)iterative quick sort
    11)horners
*/



using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int v, vector<int>parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v], parent);
}

void union_find(int u, int v, vector<int>parent, vector<int>rank) {
    u = find(u, parent);
    v = find(v, parent);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(vector<Edge> graph, int V) {
    vector<Edge> mst;
    vector<int>parent(V);
    vector<int>rank(V);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(graph.begin(), graph.end(), compare);

    for (int i = 0; i < graph.size(); i++) {
        Edge e = graph[i];
        int u = find(e.u, parent);
        int v = find(e.v, parent);

        if (u != v) {
            mst.push_back(e);
            union_find(u, v, parent, rank);
        }
    }

    cout << "Minimum Spanning Tree: " << endl;
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " - " << mst[i].v << " == " << mst[i].weight << endl;
    }
    cout << "Minimum Cost: " << endl;
    int minCost = 0;
    for (int i = 0; i < mst.size(); i++) {
        minCost += mst[i].weight;
    }
    cout << minCost << endl;
}

int main() {
    int V = 5;
    vector<Edge> graph;

    graph.push_back({0, 3, 5});
    graph.push_back({0, 1, 10});
    graph.push_back({1, 2, 2});
    graph.push_back({1, 3, 20});
    graph.push_back({2, 3, 15});
    graph.push_back({2, 4, 3});
    graph.push_back({3, 4, 12});

    kruskal(graph, V);

    return 0;
}