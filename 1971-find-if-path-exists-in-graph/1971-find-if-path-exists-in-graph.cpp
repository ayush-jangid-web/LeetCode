class Solution {
    void solve(int node,unordered_map<int,list<int>>&adj,
        vector<bool>&visited){
            visited[node] = true;

            queue<int>q;
            q.push(node);

            while(!q.empty()){
                int front = q.front();
                q.pop();

                for(auto i:adj[front]){
                    if(visited[i] == false){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>>adj;
        vector<bool>visited(n,false);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(source,adj,visited);

        if(visited[destination] == false){
            return false;
        }

        return true;
    }
};