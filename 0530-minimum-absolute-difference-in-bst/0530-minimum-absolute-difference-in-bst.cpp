/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int ans = INT_MAX;
    TreeNode* prev = NULL;

    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        TreeNode* curr = root;

        solve(root->left);

        if (prev != NULL) {
            ans = min(ans, curr->val - prev->val);
        }
        prev = root;

        solve(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
};