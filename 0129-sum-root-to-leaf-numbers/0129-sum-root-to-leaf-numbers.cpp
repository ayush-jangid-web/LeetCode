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
    int nums = 0;
    void solve(TreeNode* root,int temp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            temp = (temp*10) + root->val;
            nums+= temp;
            return;
        }

        temp = (temp*10) + root->val;
        solve(root->left,temp);
        solve(root->right,temp);
    }
public:
    int sumNumbers(TreeNode* root) {
        int i = 0;
        solve(root,i);
        return nums;
    }
};