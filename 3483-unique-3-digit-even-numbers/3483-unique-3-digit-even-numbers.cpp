class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[digits[i]]++;
        }

        int ans = 0;
        for (int i = 100; i <= 999; i++) {
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = i / 100;

            if(i%2 !=0){
                continue;
            }

            unordered_map<int,int>need;
            need[a]++;
            need[b]++;
            need[c]++;

            bool isans = true;
            for(auto &it:need){
                if(mp[it.first] < it.second){
                    isans = false;
                }
            }
            if(isans == true){
                ans++;
            }
        }
        return ans;
    }
};
