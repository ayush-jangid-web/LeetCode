class Solution {
    bool solve(int node, int target, unordered_map<int, list<int>>& adj,
               vector<bool>& visited) {

        visited[node] = true;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            if (front == target) {
                return true;
            }

            for(auto i: adj[front]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        vector<int> ans(2, 0);

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            
            vector<bool> visited(edges.size() + 1, false);

            if(solve(u,v,adj,visited)){
                ans[0] = u ;
                ans[1] = v ;
                return ans;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return ans;
    }
};