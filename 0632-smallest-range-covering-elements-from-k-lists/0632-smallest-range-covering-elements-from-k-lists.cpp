class Solution {
    class node {
    public:
        int val;
        int row;
        int col;
    };

    class compare {
    public:
        bool operator()(node* a, node* b) { return a->val > b->val; }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<node*, vector<node*>, compare> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < k; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push(new node(nums[i][0], i, 0));
        }

        vector<int> result = {mini, maxi};
        int ans = maxi - mini;
        while (!pq.empty()) {
            node* top = pq.top();
            pq.pop();

            mini = top->val;
            int row = top->row;
            int col = top->col;

            if (maxi - mini < ans) {
                result[0] = mini;
                result[1] = maxi;
                ans = maxi - mini;
            }

            if (col + 1 < nums[row].size()) {
                maxi = max(maxi, nums[row][col + 1]);
                pq.push(new node(nums[row][col + 1], row, col + 1));
            } else {
                break;
            }
        }
        return result;
    }
};