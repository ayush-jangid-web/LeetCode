class Solution {
    int solve(vector<int>&nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int smaller = INT_MIN;
        int greater = INT_MAX;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return target;
            }
            else if(nums[mid] < target){
                smaller = nums[mid];
                start = mid+1;
            }
            else{
                greater = nums[mid];
                end = mid-1;
            }
        }
        if(smaller == INT_MIN){
            return greater;
        }
        if(greater == INT_MAX){
            return smaller;
        }

        int a = target - smaller;
        int b = greater - target;

        if(a <= b){
            return smaller;
        }else{
            return greater;
        }
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();

        int ans = 0;
        
        sort(arr2.begin(),arr2.end());

        for(int i=0;i<n;i++){

            int closest = solve(arr2,arr1[i]);
            if( abs(closest - arr1[i]) > d){
                ans ++;
            }
        }

        return ans;
    }
};