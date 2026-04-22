#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Function
void BFS(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// DFS Function
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // BFS
    BFS(start, adj, V);

    // DFS
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    DFS(start, adj, visited);

    return 0;
}
