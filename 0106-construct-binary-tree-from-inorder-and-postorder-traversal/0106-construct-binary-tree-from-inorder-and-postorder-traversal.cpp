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

    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int &idx,int inorderstart,int inorderend,int n){
        if(idx < 0 || inorderstart > inorderend){
            return NULL;
        }

        int element = postorder[idx--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];

        // recursive calls
        root->right = solve(inorder,postorder,idx,position+1,inorderend,n);
        root->left = solve(inorder,postorder,idx,inorderstart,position-1,n);

        return root;
    }

    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;

        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }

        return solve(inorder,postorder,idx,0,n-1,n);
    }
};