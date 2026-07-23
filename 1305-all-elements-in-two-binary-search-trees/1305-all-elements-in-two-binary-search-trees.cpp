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
    void solve(TreeNode* root, vector<int>&temp){
        if(root == NULL){
            return ;
        }

        solve(root->left,temp);
        temp.push_back(root->val);
        solve(root->right,temp);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>temp1;
        vector<int>temp2;

        solve(root1,temp1);
        solve(root2,temp2);

        int n = temp1.size();
        int m = temp2.size();


        vector<int>ans;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(temp1[i]<temp2[j]){
                ans.push_back(temp1[i++]);
            }
            else{
                ans.push_back(temp2[j++]);
            }
        }
        while(i<n){
            ans.push_back(temp1[i++]);
        }
        while(j<m){
            ans.push_back(temp2[j++]);
        }

        return ans;
    }
};