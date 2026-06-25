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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector< vector<int> >ans;
        if(root == NULL){
            return ans;
        }
        map<int, map<int, vector<int> > >mp; // hd , level -> nodedata
        queue< pair<TreeNode*, pair<int,int> > >q; // rootnode , hd , level
        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*, pair<int,int> > temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            mp[hd][level].push_back(node->val);

            if(node->left){
                q.push(make_pair(node->left, make_pair(hd-1,level+1)));
            }

            if(node->right){
                q.push(make_pair(node->right, make_pair(hd+1,level+1)));
            }
        }

        for(auto &it:mp){
            vector<int>temp;
            for(auto &v: it.second){
                sort(v.second.begin(),v.second.end());
                for(auto &i: v.second){
                    temp.push_back(i);    
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};