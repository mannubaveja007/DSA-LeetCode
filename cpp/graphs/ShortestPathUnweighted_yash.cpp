#include <bits/stdc++.h>
using namespace std;

int shortestPathUnweighted(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == dest) return dist[u];
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1; // unreachable
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    auto addEdge = [&](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1); addEdge(0,2); addEdge(1,3); addEdge(2,4); addEdge(3,5); addEdge(4,5);
    cout << "Shortest path 0->5 (expected 3): " << shortestPathUnweighted(n, adj, 0, 5) << endl;
    return 0;
}
