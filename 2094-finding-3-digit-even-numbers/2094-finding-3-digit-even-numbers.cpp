class Solution {
    vector<int>ans;
    void solve(vector<int>&freq,int i,int num){
        if(i == 3){
            if(num%2==0){
                ans.push_back(num);
            }
            return;
        }

        for(int j=0;j<10;j++){
            if(i == 0 && j ==0){
                continue;
            }

            if(freq[j]>0){
                freq[j]--;
                solve(freq,i+1,(num*10)+j);
                freq[j]++;
            }
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        ans.clear();
        for(int i=0;i<digits.size();i++){
            freq[digits[i]]++;
        }
        solve(freq,0,0);
        return ans;
    }
};