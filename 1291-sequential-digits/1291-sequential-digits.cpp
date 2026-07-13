class Solution {
    int countdigit(int num) {
        if(num == 0){
            return 1;
        }
        int ans = 0;
        while (num != 0) {
            ans++;
            num /= 10;
        }
        return ans;
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";

        int lowdigit = countdigit(low);
        int highdigit = countdigit(high);

        vector<int> result;

        for (int k = 0; k <= min(highdigit,9) - lowdigit; k++) {
            // windoe for low

            // first window
            int i = 0;
            int j = 0;

            string temp = "";
            while (j < lowdigit + k) {
                temp += num[j++];
            }
            if (stoi(temp) >= low && stoi(temp) <= high) {
                result.push_back(stoi(temp));
            }

            // rest window
            while (i < j && j < 9) {
                temp.erase(temp.begin());
                temp += num[j++];
                i++;

                if (stoi(temp) >= low && stoi(temp) <= high) {
                    result.push_back(stoi(temp));
                }
            }
        }
        return result;
    }
};