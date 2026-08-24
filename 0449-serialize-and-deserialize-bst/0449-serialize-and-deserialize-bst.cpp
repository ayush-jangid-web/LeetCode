/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void solvepre(TreeNode* root,string& preorder){
        if(root == NULL){
            return;
        }

        preorder += to_string(root->val) + ',';

        solvepre(root->left,preorder);
        solvepre(root->right,preorder);
    }

    TreeNode* solve(vector<int> &nums,int maxi,int mini,int &i){
        if(i >= nums.size()){
            return NULL;
        }
        if(nums[i] > maxi || nums[i] < mini){
            return NULL;
        }

        TreeNode* root = new TreeNode(nums[i++]);
        root->left = solve(nums,root->val,mini,i);
        root->right = solve(nums,maxi,root->val,i);

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string preorder = "";
        solvepre(root,preorder);
        return preorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>nums;
        int i = 0;
        int num = 0;
        while(i < data.length()){
            char ch = data[i++];
            if(ch == ','){
                nums.push_back(num);
                num = 0;
            }
            else{
                num = (num * 10) + (ch - '0');
            }
        }
        int k = 0;
        return solve(nums,INT_MAX,INT_MIN,k);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;