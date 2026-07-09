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
    unordered_map<int,int>mp;

    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &idx,int inorderstart,int inorderend,int n){
        if(idx >= n || inorderstart > inorderend){
            return NULL;
        }

        int element = preorder[idx++];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];

        // recursive calls
        root->left = solve(preorder,inorder,idx,inorderstart,position-1,n);
        root->right = solve(preorder,inorder,idx,position+1,inorderend,n);

        return root;
    }

    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();

        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }

        return solve(preorder,inorder,idx,0,n-1,n);
    }
};