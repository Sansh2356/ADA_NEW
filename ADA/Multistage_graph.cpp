#include <iostream>
#include <vector>
#include <limits>
using namespace std;

pair<vector<int>, int> multistage_graph(vector<vector<pair<int, int>>>& graph, vector<vector<int>>& stages) {
    int num_stages = stages.size();
    int num_vertices = graph.size();

    vector<int> min_costs(num_vertices, numeric_limits<int>::max());

    min_costs[stages[num_stages - 1][0]] = 0;

    for (int i = num_stages - 2; i >= 0; i--) {
        for (int j : stages[i]) {
            for (const auto& edge : graph[j]) {
                int neighbor = edge.first;
                int cost = edge.second;

                if (min_costs[neighbor] > min_costs[j] + cost) {
                    min_costs[neighbor] = min_costs[j] + cost;
                }
            }
        }
    }

    vector<int> path;
    int current_vertex = 0;
    for (int i = 0; i < num_stages - 1; i++) {
        path.push_back(current_vertex);
        for (int j : stages[i]) {
            if (min_costs[current_vertex] == min_costs[j] + graph[j][current_vertex]) {
                current_vertex = j;
                break;
            }
        }
    }
    path.push_back(current_vertex);

    return {path, min_costs[stages[num_stages - 1][0]]};
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {2, 3}, {3, 4}, {3, 5}, {3, 6}},
        {{4, 7}, {4, 8}, {5, 7}, {5, 8}, {6, 7}, {6, 8}},
        {{7, 9}, {8, 9}}
    };

    vector<vector<int>> stages = {
        {8},          // Sink stage
        {6, 7},       // Stage K-1
        {3, 4, 5},    // Stage K-2
        {1, 2}        // Source stage
    };

    auto result = multistage_graph(graph, stages);

    cout << "Minimum cost path: ";
    for (int vertex : result.first) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "Minimum cost: " << result.second << endl;

    return 0;
}