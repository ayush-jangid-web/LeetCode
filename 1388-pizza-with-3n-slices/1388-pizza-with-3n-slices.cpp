class Solution {
    int solve(int idx,int endidx,int n, vector<int>&slices,vector<vector<int>>&dp){
        if(n == 0 || idx > endidx){
            return 0;
        }
        if(dp[idx][n] != -1){
            return dp[idx][n];
        }

        int include = slices[idx] + solve(idx+2,endidx,n-1,slices,dp);
        int exclude = 0 + solve(idx+1,endidx,n,slices,dp);

        return dp[idx][n] = max(include,exclude);
    }

    int solveTab(vector<int>&slices){
        int k = slices.size();

        vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
        vector<vector<int>>dp2(k+2,vector<int>(k+2,0));

        for(int idx = k-2;idx>=0;idx--){
            for(int n = 1;n<=k/3;n++){

                int include = slices[idx] + dp1[idx+2][n-1];
                int exclude = 0 + dp1[idx+1][n];

                dp1[idx][n] = max(include,exclude);
            }
        }

        for(int idx = k-1;idx>=1;idx--){
            for(int n = 1;n<=k/3;n++){

                int include = slices[idx] + dp2[idx+2][n-1];
                int exclude = 0 + dp2[idx+1][n];

                dp2[idx][n] = max(include,exclude);
            }
        }

        return max(dp1[0][k/3] , dp2[1][k/3]);
    }


    int solveSpace(vector<int>&slices){
        int k = slices.size();

        vector<int>prev1(k+2,0);
        vector<int>curr1(k+2,0);
        vector<int>next1(k+2,0);

        for(int idx = k-2;idx>=0;idx--){
            for(int n = 1;n<=k/3;n++){

                int include = slices[idx] + next1[n-1];
                int exclude = 0 + curr1[n];

                prev1[n] = max(include,exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }

        vector<int>prev2(k+2,0);
        vector<int>curr2(k+2,0);
        vector<int>next2(k+2,0);

        for(int idx = k-1;idx>=1;idx--){
            for(int n = 1;n<=k/3;n++){

                int include = slices[idx] + next2[n-1];
                int exclude = 0 + curr2[n];

                prev2[n] = max(include,exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }

        return max(curr1[k/3] , curr2[k/3]);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // vector<vector<int>>dp1(k,vector<int>(k,-1));
        // vector<vector<int>>dp2(k,vector<int>(k,-1));

        // int a = solve(0,k-2,k/3,slices,dp1);
        // int b = solve(1,k-1,k/3,slices,dp2);

        // return max(a,b);

        // return solveTab(slices);

        return solveSpace(slices);
    }
};