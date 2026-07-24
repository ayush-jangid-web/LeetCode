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
    TreeNode* solve(TreeNode* root,int val){
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        if(root->val > val){
            if(root->left){
                root->left = solve(root->left,val);
            }
            else{
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
        }
        else{
            if(root->right){
                root->right = solve(root->right,val);
            }
            else{
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }
        }
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};