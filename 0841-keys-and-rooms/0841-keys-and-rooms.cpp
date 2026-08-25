class Solution {
    void solve(int node, vector<vector<int>>& rooms, vector<int>& visited) {
        visited[node] = true;

        for (auto i : rooms[node]) {

            if (visited[i] == false) {
                solve(i, rooms, visited);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<int> visited(rooms.size(), false);

        solve(0, rooms, visited);

        for (int i = 0; i < rooms.size(); i++) {
            if (visited[i] == false){
                return false;
            }
        }
        return true;
    }
};