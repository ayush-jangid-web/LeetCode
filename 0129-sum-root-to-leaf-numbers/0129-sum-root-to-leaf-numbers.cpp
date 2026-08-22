/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
    void solve(TreeNode* root,int temp){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            ans += (temp*10)+root->val;
            return;
        }

        temp = (temp * 10) + root->val;
        solve(root->left,temp);
        solve(root->right,temp);
    }
public:
    int sumNumbers(TreeNode* root) {
        solve(root,0);

        return ans;
    }
};