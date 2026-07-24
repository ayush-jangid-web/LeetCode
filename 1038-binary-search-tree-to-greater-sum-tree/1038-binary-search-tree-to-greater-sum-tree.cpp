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
    TreeNode* solve(TreeNode* root,int &sum){
        if(root == NULL){
            return NULL;
        }

        root->right = solve(root->right,sum);
        sum += root->val;
        root->val = sum;
        root->left = solve(root->left,sum);

        return root;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        return solve(root,sum);
    }
};