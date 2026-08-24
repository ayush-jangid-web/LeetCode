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
    void solve(TreeNode* root,int child,int parent,int grandparent){
        if(root == NULL){
            return;
        }
        grandparent = parent;
        parent = child;
        child = root->val;

        if(grandparent != -1 && grandparent % 2 == 0){
            ans += root->val;
        }
        solve(root->left,child,parent,grandparent);
        solve(root->right,child,parent,grandparent);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        solve(root,-1,-1,-1);
        return ans;
    }
};