class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;

        string temp = "";
        for(int i=0;i<n;i++){
            temp += ".";
        }
        ans.push_back(temp);
        temp = "";
        for(int i = 0;i<n-1;i++){
            temp += '#';
        }
        temp += ".";
        for(int i = 1;i<m;i++){
            ans.push_back(temp);
        }
        return ans;
    }
};