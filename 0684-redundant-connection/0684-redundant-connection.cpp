class Solution {
    bool solve(int node, int target, unordered_map<int, list<int>>& adj,
               vector<bool>& visited) {
        if(node == target){
            return true;
        }

        visited[node] = true;

        for(auto i: adj[node]){
            if(!visited[i]){
                bool is = solve(i,target,adj,visited);
                if(is){
                    return true;
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