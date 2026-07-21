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
public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        int n = ans.size();
        if(n>=k){
            int result=0;
            for(int i=0;i<k;i++){
                result = ans[i];
            }
            return result;
        }
        return -1;
    }
};