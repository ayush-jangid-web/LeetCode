class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<string>temp(numRows);

        int k = 0;
        int i = 0;
        while(i < n){
            while(i<n && k < numRows){
                temp[k] += s[i++];
                k++;
            }
            k = numRows-2;
            while(i<n && k > 0){
                temp[k] += s[i++];
                k--;
            }
            k=0;
        }

        string result = "";
        for(auto &it:temp){
            result += it;
        }
        return result;
    }
};