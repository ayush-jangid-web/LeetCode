class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        long long target = 0;
        for (int i = 0; i < skill.size(); i++) {
            target += skill[i];
        }
        target = target / (skill.size() / 2);

        while (i < j) {
            if (skill[i] + skill[j] == target) {
                ans += skill[i] * skill[j];
                i++;
                j--;
            } else {
                return -1;
            }
        }

        return ans;
    }
};
