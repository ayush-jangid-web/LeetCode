class Solution {
    void solve(int n,int open, int close, string temp,vector<string>&ans){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            solve(n,open+1,close,temp+"(",ans);
        }
        if(close < open){
            solve(n,open,close+1,temp+")",ans);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};