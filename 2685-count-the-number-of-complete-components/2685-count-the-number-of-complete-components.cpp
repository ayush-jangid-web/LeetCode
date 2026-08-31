class Solution {
    void solve(int node, vector<bool>& visited,
               unordered_map<int, list<int>>& adj, int& nodecount,
               int& edgecount) {
        visited[node] = true;
        nodecount++;

        for (auto nbr : adj[node]) {
            edgecount++;
            if (visited[nbr] == false) {
                solve(nbr, visited, adj, nodecount, edgecount);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> components;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int nodecount = 0;
            int edgecount = 0;
            if (visited[i] == false) {
                solve(i, visited, adj, nodecount, edgecount);

                edgecount /= 2;

                if (edgecount == nodecount * (nodecount - 1) / 2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};