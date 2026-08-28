class Solution {
    string backtrack(int i, map<char, int>& halftarget, string& ans) {
        if (i == 0) {
            return "";
        }

        int j = i - 1;
        while (j >= 0) {
            char k = ans.back();
            // removing last entry
            ans.pop_back();
            halftarget[k]++;

            // finding just greater
            for (char c = k + 1; c <= 'z'; c++) {
                if (halftarget[c] > 0) {
                    ans += c;
                    halftarget[c]--;

                    // found
                    // storing remaining char in sorted order
                    for (auto& it : halftarget) {
                        while (it.second > 0) {
                            ans += it.first;
                            it.second--;
                        }
                    }
                    return ans;
                }
            }
            // not found just greater
            // reducing / backtrack;
            j--;
        }
        // no solution found
        return "";
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        string ans = "";
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        char center;
        if (n % 2 == 0) {
            // even
            for (auto& it : mp) {
                if (it.second % 2 != 0) {
                    return ans;
                }
            }
        } else {
            // odd
            int o = 0;
            for (auto& it : mp) {
                if (it.second % 2 != 0) {
                    o++;
                    center = it.first;
                }
            }
            if (o != 1) {
                return ans;
            }
        }

        int half = n / 2;
        map<char, int> halftarget;
        for (auto& it : mp) {
            halftarget[it.first] = it.second / 2;
        }

        string newtarget = target.substr(0, half);

        ////
        for (int i = 0; i < half; i++) {
            // adding same char
            char ch = newtarget[i];
            if (halftarget[ch] > 0) {
                ans += ch;
                halftarget[ch]--;
            } else {
                // finding just greater then ch
                bool found = false;
                for (char c = ch + 1; c <= 'z'; c++) {
                    if (halftarget[c] > 0) {
                        found = true;
                        ans += c;
                        halftarget[c]--;
                        // found
                        // storing remaining char in sorted order
                        for (auto& it : halftarget) {
                            while (it.second > 0) {
                                ans += it.first;
                                it.second--;
                            }
                        }
                        break;
                    }
                }

                if (found) {
                    break;
                }

                ans = backtrack(i, halftarget, ans);

                if (ans == "") {
                    return "";
                }

                break;
            }
        }

        string right = ans;

        reverse(right.begin(), right.end());

        string result = ans;

        if (n % 2 == 1) {
            result += center;
        }

        result += right;

        if (result > target) {
            return result;
        }

        // rebuild

        halftarget.clear();
        for (auto& it : mp) {
            halftarget[it.first] = it.second / 2;
        }

        for (char ch : ans) {
            halftarget[ch]--;
        }

        ans = backtrack(half, halftarget, ans);

        if (ans == "") {
            return ans;
        }

        right = ans;

        reverse(right.begin(), right.end());
        result = ans;

        if (n % 2 == 1) {
            result += center;
        }

        result += right;

        if (result > target) {
            return result;
        }

        return "";
    }
};