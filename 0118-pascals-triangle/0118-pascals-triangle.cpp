class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        ans.push_back({1});

        for(int i=1;i<numRows;i++){
            vector<int>temp = ans.back();
            if(temp.size() < 2){
                ans.push_back({1,1});
            }
            else{
                int size = temp.size();
                vector<int>next;
                next.push_back(1);
                for(int j=0;j<size-1;j++){
                    int elem = temp[j] + temp[j+1];
                    next.push_back(elem);
                }
                next.push_back(1);
                ans.push_back(next);
            }
        }
        return ans;
    }
};