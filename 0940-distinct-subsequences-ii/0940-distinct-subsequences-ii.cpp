#define mod 1000000007
class Solution {
    // void solve(string& s,int n,string t,int i,unordered_map<string,int>&mp){
    //     if(i == n){
    //         mp[t]++;
    //         return;
    //     }
    //     //include
    //     solve(s,n,t+s[i],i+1,mp);
    //     //exclude
    //     solve(s,n,t,i+1,mp);
    // }

    int solve(string& s,int i,int n,vector<int>&dp){
        if( i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        long long total = 0;
        vector<bool>visited(26,false);

        for(int j=i;j<n;j++){
            int ch = s[j] - 'a';

            if(visited[ch] != true){
                visited[ch] = true;
                total += solve(s,j+1,n,dp);
            }
        }
        return dp[i] = (total + 1) % mod;
    }
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        // int ans = 0;
        // unordered_map<string,int>mp;

        // solve(s,n,"",0,mp);

        // for(auto &it:mp){
        //     if(it.second > 0){
        //         ans++;
        //     }
        //     if(it.first == ""){
        //         ans--;
        //     }
        // }
        // return ans % mod;
        vector<int>dp(n+1,-1);
        int ans = solve(s,0,n,dp) - 1;
        if(ans < 0){
            return ans += mod;
        }
        return ans % mod;
    }
};