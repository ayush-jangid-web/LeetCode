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
        if(root==NULL){
            return;
        }
        
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        solve(root);
        long long pre = LLONG_MIN;
        for(auto &it:ans){
            if(pre < it){
                pre = it;
            }
            else{
                return false;
            }
        }
        return true;

    }
};