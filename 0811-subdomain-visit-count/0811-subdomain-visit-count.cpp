class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string num = "";
            string domain = "";

            int m = cpdomains[i].length();

            // num calculate
            for (int j = 0; j < m; j++) {
                char ch = cpdomains[i][j];
                num += ch;
                if (ch == ' ') {
                    break;
                }
            }

            // domain calculate
            for (int j = m - 1; j >= 0; j--) {
                char ch = cpdomains[i][j];
                if (ch == '.') {
                    reverse(domain.begin(), domain.end());
                    // push in ans;
                    mp[domain] += stoi(num);
                    reverse(domain.begin(), domain.end());
                    // continue;
                }
                if (ch == ' ') {
                    reverse(domain.begin(), domain.end());
                    // push in ans;
                    mp[domain] += stoi(num);
                    reverse(domain.begin(), domain.end());
                    break;
                }
                domain += ch;
            }
        }

        for (auto& it : mp) {
            string result = to_string(it.second);
            result += " ";
            result += it.first;

            ans.push_back(result);
        }
        return ans;
    }
};