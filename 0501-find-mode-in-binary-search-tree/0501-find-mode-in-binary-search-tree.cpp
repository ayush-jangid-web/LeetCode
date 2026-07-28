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
    TreeNode* prev = NULL;
    int maxi = 0;
    int n = 1;
    void solve(TreeNode* root,vector<int>&ans){
        if(root == NULL){
            return ;
        }

        TreeNode* curr = root;

        solve(root->left,ans);

        if(prev!=NULL){
            if(prev->val == curr->val){
                n++;
            }
            else{
                n=1;
            }
        }

        if(n > maxi){
            ans.clear();
            ans.push_back(curr->val);
            maxi = n;
        }
        else if(n == maxi){
            ans.push_back(curr->val);
        }
        prev = curr;
        solve(root->right,ans);
        
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};