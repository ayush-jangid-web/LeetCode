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
    vector<int>temp;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* balance(vector<int> &data,int left,int right){
        if(left>right){
            return NULL;
        }

        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(data[mid]);

        root->left = balance(data,left,mid-1);
        root->right = balance(data,mid+1,right);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = temp.size();
        TreeNode* ans = balance(temp,0,n-1);
        return ans;
    }
};