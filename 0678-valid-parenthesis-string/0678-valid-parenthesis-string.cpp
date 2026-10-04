class Solution {
    bool solve(int idx, string& s, int bal) {
        if (idx == s.length()) {
            if (bal == 0) {
                return true;
            }
            return false;
        }
        if (bal < 0) {
            return false;
        }

        if (s[idx] == '(') {
            bal++;
            return solve(idx + 1, s, bal);
        } 
        else if (s[idx] == ')') {
            bal--;
            return solve(idx + 1, s, bal);
        } 
        else { // *
            // * -> (
            bal++;
            bool a = solve(idx + 1, s, bal);
            bal--;

            // * -> )
            bal--;
            bool b = solve(idx + 1, s, bal);
            bal++;

            // * -> ' '
            bool c = solve(idx + 1, s, bal);

            return ((a || b) || c);
        }
    }


    bool solveMemo(int idx,string& s,int bal,vector<vector<int>>&dp){
        if(bal < 0){
            return false;
        }
        if(idx == s.length()){
            if(bal == 0){
                return true;
            }
            return false;
        }
        if(dp[idx][bal] != -1){
            return dp[idx][bal];
        }
        
        if(s[idx] == '('){
            return dp[idx][bal] = solveMemo(idx+1,s,bal+1,dp);
        }
        else if(s[idx] == ')'){
            return dp[idx][bal] = solveMemo(idx+1,s,bal-1,dp);
        }
        else{
            // (
            bool a = solveMemo(idx+1,s,bal+1,dp);

            // )
            bool b = solveMemo(idx+1,s,bal-1,dp);

            // ' '
            bool c = solveMemo(idx+1,s,bal,dp);

            return dp[idx][bal] = ((a || b) || c); 
        }
    }
public:
    bool checkValidString(string s) { 
        // return solve(0, s, 0);
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMemo(0,s,0,dp);
    }
};