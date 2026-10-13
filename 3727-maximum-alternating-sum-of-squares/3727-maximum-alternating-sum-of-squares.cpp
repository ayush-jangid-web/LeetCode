class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>temp;
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());

        long long ans = 0;
        int i = 0;
        int j = n-1;

        while(i < j){
            temp.push_back(nums[j--]);
            temp.push_back(nums[i++]);
        }
        if(i == j){
            temp.push_back(nums[i]);
        }

        for(int k=0;k<n;k++){
            if(k%2==0){
                ans += (temp[k]*temp[k]*1LL);
            }
            else{
                ans -= (temp[k]*temp[k]*1LL);
            }
        }
        return ans;
    }
};