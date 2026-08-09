class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int>pq;
        int n = score.size();

        for(int i=0;i<n;i++){
            pq.push(score[i]);
        }

        vector<string>ans;
        unordered_map<int,string>mp;

        int cnt=1;
        while(!pq.empty()){
            if(cnt == 1){
                mp[pq.top()] = "Gold Medal";
                pq.pop();
                cnt++;
            }
            else if(cnt == 2){
                mp[pq.top()] = "Silver Medal";
                pq.pop();
                cnt++;
            }
            else if(cnt == 3){
                mp[pq.top()] = "Bronze Medal";
                pq.pop();
                cnt++;
            }
            else{
                mp[pq.top()] = to_string(cnt);
                pq.pop();
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            ans.push_back(mp[score[i]]);
        }
        return ans;
    }
};