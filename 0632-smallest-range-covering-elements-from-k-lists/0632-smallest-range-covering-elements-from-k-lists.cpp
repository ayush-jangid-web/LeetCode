class Solution {
    class node {
    public:
        int val;
        int row;
        int col;

        node(int val, int row, int col) {
            this->val = val;
            this->row = row;
            this->col = col;
        }
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
            maxi = max(maxi, nums[i][0]);
            node* temp = new node(nums[i][0], i, 0);
            pq.push(temp);
        }

        mini = pq.top()->val;
        int ans = maxi - mini;
        vector<int> result = {mini, maxi};

        while (!pq.empty()) {
            node* top = pq.top();
            pq.pop();

            mini = top->val;
            int row = top->row;
            int col = top->col;

            if (maxi - mini < ans) {
                ans = maxi - mini;
                result[0] = mini;
                result[1] = maxi;
            }
            if (col + 1 < nums[row].size()) {
                maxi = max(maxi, nums[row][col + 1]);
                node* next = new node(nums[row][col + 1], row, col + 1);
                pq.push(next);

            }
            else{
                break;
            }
        }
        return result;
    }
};