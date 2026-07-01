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
    long long sum = 0;
    void solve(TreeNode* root,bool left){
        if(root == NULL){
            return;
        }


        if((root->left == NULL && root->right == NULL) && left){
            sum += root->val;
        }
        
        solve(root->left,true);

        solve(root->right,false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,false);
        return sum;
    }
};