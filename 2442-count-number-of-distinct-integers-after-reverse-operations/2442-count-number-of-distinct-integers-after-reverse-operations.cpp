class Solution {
    int solve(int n){
        int a = 0;
        while(n!=0){
            a = a*10 + n%10;
            n /= 10;
        }
        return a;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(solve(nums[i]));
        }
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<n*2;i++){
            if(mp[nums[i]]<1){
                mp[nums[i]]++;
                cnt++;
            }
        }
        return cnt;
    }
};