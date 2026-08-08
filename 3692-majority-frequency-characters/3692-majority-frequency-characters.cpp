class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int>mp;
        int n = s.length();
        
        map<int,string>temp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(auto &it:mp){
            if(it.second > 0){
                temp[it.second]+=it.first;
            }            
        }

        int maxi = 0;
        for(auto &it:temp){
            if(it.second.length() > maxi){
                maxi = it.second.length();
            }
        }
        string ans="";
        for(auto &it:temp){
            if(it.second.size() == maxi){
                ans= it.second;
            }
        }
        return ans;
    }
};