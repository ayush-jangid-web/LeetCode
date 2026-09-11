class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<pair<int,int>>result;

        int n = skill.size();
        sort(skill.begin(),skill.end());

        int i=0;
        int j = n-1;
        long long target = 0;
        for(int i=0;i<n;i++){
            target += skill[i];
        }
        target = target/(n/2);

        while(i<j){
            if(skill[i]+skill[j] == target){
                result.push_back(make_pair(skill[i],skill[j]));
                i++;
                j--;
            }
            else{
                return -1;
            }
        }

        long long ans = 0;
        for(auto &it:result){
            ans += it.first*it.second;
        }
        return ans;
    }
};

