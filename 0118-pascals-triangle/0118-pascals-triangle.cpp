class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> temp;
            temp = ans.back();

            if (temp.size() < 2) {
                ans.push_back({1, 1});
            } else {
                vector<int> next;
                next.push_back(1);
                for (int j = 0; j < temp.size() - 1; j++) {
                    next.push_back(temp[j] + temp[j + 1]);
                }
                next.push_back(1);
                ans.push_back(next);
            }
        }
        return ans;
    }
};