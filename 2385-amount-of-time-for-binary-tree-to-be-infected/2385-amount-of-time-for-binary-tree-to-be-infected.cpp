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

    TreeNode* mapandfind(unordered_map<TreeNode*,TreeNode*> &childtoparent,TreeNode* root, int start){
        TreeNode* target = NULL;

        queue<TreeNode*>q;
        q.push(root);

        childtoparent[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == start){
                target = front;
            }

            if(front->left){
                childtoparent[front->left] = front;
                q.push(front->left);
            }

            if(front->right){
                childtoparent[front->right] = front;
                q.push(front->right);
            }
        }
        return target;
    }

    int burn(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &childtoparent){
        int ans = 0;

        unordered_map<TreeNode*,bool>visit;
        visit[root] = true;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            bool flag = false;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visit[front->left]){
                    visit[front->left] = true;
                    q.push(front->left);
                    flag = true;
                }

                if(front->right && !visit[front->right]){
                    visit[front->right] = true;
                    q.push(front->right);
                    flag = true;
                }

                if(childtoparent[front] && !visit[childtoparent[front]]){
                    visit[childtoparent[front]] = true;
                    q.push(childtoparent[front]);
                    flag = true;
                }
            }
            if(flag == true){
                ans++;
            }
        }
        return ans;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> childtoparent;

        TreeNode* target = mapandfind(childtoparent,root,start);

        return burn(target,childtoparent);
    }
};