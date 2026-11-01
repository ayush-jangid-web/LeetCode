class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int M = INT_MAX;
        int cnt = 0;

        for(int i=0;i<n;i++){
            M = min(M,nums[i]);
        }

        for(int i=0;i<n;i++){
            cnt += abs(M-nums[i]);
        }
        return cnt;
    }
};