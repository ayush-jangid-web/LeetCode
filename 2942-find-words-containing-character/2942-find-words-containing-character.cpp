class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int>ans;
        for(int i=0;i<n;i++){
            string temp = words[i];
            int l = temp.size();
            for(int j=0;j<l;j++){
                if(temp[j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};