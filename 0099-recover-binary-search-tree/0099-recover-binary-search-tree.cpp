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
    vector<int>ans;
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    int k=0;
    void bst(TreeNode* root,vector<int>&ans){
        if(root == NULL){
            return;
        }

        bst(root->left,ans);
        root->val = ans[k++];
        bst(root->right,ans);
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
        sort(ans.begin(),ans.end());
        bst(root,ans);
        return;
    }
};