class Solution {
    int solveSum(int n){
        int ans = 0;
        while(n!=0){
            int digit = n%10;
            ans += digit;
            n /= 10;
        }
        return ans;
    }
public:
    static bool sortValues(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>&b){
        if(a.first == b.first){
            return a.second.first < b.second.first;
        }
        return a.first < b.first;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // digitSum -> num -> orgIdx
        vector<pair<int,pair<int,int>>>temp;

        for(int i=0;i<n;i++){
            int digitSum = solveSum(nums[i]);
            temp.push_back( {digitSum, {nums[i], i}});
        }

        // sort on basis of digitsum and if same then basis of num;
        sort(temp.begin(),temp.end(), sortValues); 

        // cheak for the swap by cycle detection 
        // following the orgindex
        vector<bool>visited(n,false);

        int swapCount = 0;
        
        for(int i=0;i<n;i++){
            if(visited[i] || temp[i].second.second == i){
                continue;
            }

            int cycleCnt = 0;
            int j = i;

            while(!visited[j]){
                visited[j] = true;
                cycleCnt ++;
                j = temp[j].second.second;
            }

            if(cycleCnt > 1){
                swapCount += cycleCnt - 1;
            }
        }

        return swapCount;

    }
};