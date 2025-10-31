#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto &p : prerequisites) {
        // p[1] -> p[0]
        adj[p[1]].push_back(p[0]);
        indeg[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
    int taken = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); ++taken;
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return taken == numCourses;
}

int main() {
    int n = 4;
    vector<vector<int>> req = {{1,0},{2,1},{3,2}}; // linear chain
    cout << "Can finish (expected 1): " << canFinish(n, req) << endl;
    vector<vector<int>> cyc = {{1,0},{0,1}}; // cycle
    cout << "Can finish (cycle expected 0): " << canFinish(2, cyc) << endl;
    return 0;
}
