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
    vector<TreeNode*>l;
    void solve(TreeNode* root){
        if(root == NULL){
            return ;
        }
        solve(root->left);
        l.push_back(root);
        solve(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        int n = l.size();

        for(int i=0;i<n-1;i++){
            l[i]->left = NULL;
            l[i]->right = l[i+1];
        }

        l[n-1]->left = NULL;
        l[n-1]->right = NULL;

        return l[0];
    }
};