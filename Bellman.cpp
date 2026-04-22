#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    if (V <= 0 || E <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

        if (edges[i].u >= V || edges[i].v >= V || edges[i].u < 0 || edges[i].v < 0) {
            cout << "Invalid vertex index!" << endl;
            return 0;
        }
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    if (source < 0 || source >= V) {
        cout << "Invalid source!" << endl;
        return 0;
    }

    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool negativeCycle = false;

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Graph contains Negative Weight Cycle\n";
    } else {
        cout << "\nShortest distances from source:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            if (dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];
            cout << endl;
        }
    }

    return 0;
}
