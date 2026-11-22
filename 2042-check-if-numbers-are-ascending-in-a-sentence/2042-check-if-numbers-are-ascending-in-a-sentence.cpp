class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.length();

        vector<string> temp;

        string a = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                temp.push_back(a);
                a = "";
            } else {
                a += s[i];
            }
        }
        if (a != "") {
            temp.push_back(a);
            a = "";
        }

        int m = temp.size();
        int prev = -1;

        for (int i = 0; i < m; i++) {
            string b = temp[i];

            if (isdigit(b[0])) {
                if (prev >= stoi(b)) {
                    return false;
                }
                prev = stoi(b);
            }
        }
        return true;
    }
};