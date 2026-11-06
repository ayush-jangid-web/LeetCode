class Solution {
    bool match(string s, string word) {
        int n = s.length();
        int m = word.length();

        vector<string> first;
        vector<string> second;

        int i = 0;
        char prev = '\0';
        string group = "";

        while (i < n) {
            char ch = s[i];
            if (prev == '\0') {
                group = ch;
            }
            if ((prev != '\0') && prev == ch) {
                group += ch;
            }
            if ((prev != '\0') && prev != ch) {
                first.push_back(group);
                group = ch;
            }
            prev = ch;
            i++;
        }
        first.push_back(group);

        i = 0;
        prev = '\0';
        group = "";

        while (i < m) {
            char ch = word[i];
            if (prev == '\0') {
                group = ch;
            }
            if ((prev != '\0') && prev == ch) {
                group += ch;
            }
            if ((prev != '\0') && prev != ch) {
                second.push_back(group);
                group = ch;
            }
            prev = ch;
            i++;
        }
        second.push_back(group);

        int p = first.size();
        int q = second.size();

        if (p != q) {
            return false;
        }

        for (int i = 0; i < p; i++) {
            char ch1 = first[i][0];
            char ch2 = second[i][0];
            if (ch1 != ch2) {
                return false;
            }

            int size1 = first[i].length();
            int size2 = second[i].length();

            if (size1 < 3) {
                if (size1 != size2) {
                    return false;
                }
            }

            else {
                // size1 >= 3
                if (size1 < size2) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int expressiveWords(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            string word = words[i];
            bool result = match(s, word);

            if (result == true) {
                ans++;
            }
        }
        return ans;
    }
};