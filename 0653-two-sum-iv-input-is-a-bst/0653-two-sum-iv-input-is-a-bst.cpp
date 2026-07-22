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
            return ;
        }
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int n = ans.size();
        int i =0;
        int j =n-1;
        while(i<j){
            if(ans[i]+ans[j] == k){
                return true;
            }
            if(ans[i] + ans[j] < k){
                i++;
            }
            else if(ans[i]+ans[j] > k){
                j--;
            }
        }
        return false;
    }
};