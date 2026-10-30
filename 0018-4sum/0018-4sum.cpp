class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<n-3;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int a = nums[i];
                int b = nums[j];

                int p = j+1;
                int q = n-1;

                while(p < q){
                    int c = nums[p];
                    int d = nums[q];

                    long long sum = 1LL* a + b + c + d;

                    if(sum == target){
                        ans.push_back({a,b,c,d});
                        p++;
                        q--;

                        while(p < q && nums[p] == nums[p-1]){
                            p++;
                        }
                        while(p < q && nums[q] == nums[q+1]){
                            q--;
                        }
                    }
                    else if(sum > target){
                        q--;
                    }
                    else{
                        p++;
                    }
                }
            }
        }
        return ans;
    }
};