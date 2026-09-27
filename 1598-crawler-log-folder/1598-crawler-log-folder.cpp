class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();

        int ans = 0;
        for(int i=0;i<n;i++){
            string s = logs[i];
            if(ans<0){
                ans = 0;
            }
            if(s == "../"){
                ans--;
            }
            else if(s == "./"){
                continue;
            }
            else{
                ans++;
            }
        }
        if(ans < 0){
            return 0;
        }
        return ans;
    }
};