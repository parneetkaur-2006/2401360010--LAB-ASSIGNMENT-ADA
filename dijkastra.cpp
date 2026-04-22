#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // {distance, node}

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

  
    if (n <= 0 || m < 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<vector<pii>> adj(n);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

      
        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "Invalid vertex index!" << endl;
            return 0;
        }

    
        if (w < 0) {
            cout << "Negative weights not allowed in Dijkstra!" << endl;
            return 0;
        }

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    if (source < 0 || source >= n) {
        cout << "Invalid source!" << endl;
        return 0;
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;

            if (dist[node] != INT_MAX && dist[node] + wt < dist[adjNode]) {
                dist[adjNode] = dist[node] + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "\nShortest distances from source:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
