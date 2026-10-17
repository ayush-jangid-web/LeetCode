class Solution {
    int solveSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    static bool sortValue(pair<int, pair<int, int>>& a,pair<int, pair<int, int>>& b) {
        if (a.first == b.first) {
            return a.second.first < b.second.first;
        }
        return a.first < b.first;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // digitSum -> num -> orgIdx
        vector<pair<int,pair<int,int>>>temp;

        for(int i=0;i<n;i++){
            temp.push_back( {solveSum(nums[i]), {nums[i], i}});
        }

        // sort on basis of digitsum and if same then basis of num;
        sort(temp.begin(),temp.end(),sortValue);

        // cheak for the swap by cycle detection
        // following the orgindex
        vector<bool>visited(n,false);

        int swap = 0;
        for(int i=0;i<n;i++){
            if(visited[i] || temp[i].second.second == i){
                continue;
            }

            int cyclecnt = 0;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                cyclecnt++;
                j = temp[j].second.second;
            }

            if(cyclecnt > 1){
                swap += cyclecnt - 1;
            }
        }
        return swap;
    }
};