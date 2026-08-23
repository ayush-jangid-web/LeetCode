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
    void solve(TreeNode* root,int maxi){
        if(root == NULL){
            return;
        }
        if(maxi <= root->val){
            ans++;
            maxi = root->val;
        }
        solve(root->left,maxi);
        solve(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return ans;
    }
};