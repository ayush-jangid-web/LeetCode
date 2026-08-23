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
 
 // 0 -> FALSE
 // 1 -> TRUE
 // 2 -> OR
 // 3 -> AND

class Solution {
    bool solve(TreeNode* root){
        if(root == NULL){
            return true;
        }
        if(root->val == 0){
            return false;
        }
        else if(root->val == 1){
            return true;
        }
        else if(root->val == 2){
            bool left = solve(root->left);
            bool right = solve(root->right);
            return left || right;
        }
        else{
            bool left = solve(root->left);
            bool right = solve(root->right);
            return left && right;
        }
    }
public:
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};