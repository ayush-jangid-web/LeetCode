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
    TreeNode* mapAndFindTarget(int start,TreeNode* root,unordered_map<TreeNode*,TreeNode*>&childToParent){
        TreeNode* target = NULL;
        queue<TreeNode*>q;
        q.push(root);
        childToParent[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == start){
                target = front;
            }
            if(front->left){
                childToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                childToParent[front->right] = front;
                q.push(front->right);
            }           
        }
        return target;
    };

    int burn(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&childToParent){
        int ans = 0;
        unordered_map<TreeNode*,bool>isVisited;
        isVisited[root] = true;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            
            bool flag = false;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !isVisited[front->left]){
                    flag = true;
                    q.push(front->left);
                    isVisited[front->left] = true;
                }

                if(front->right && !isVisited[front->right]){
                    flag = true;
                    q.push(front->right);
                    isVisited[front->right] = true;
                }

                if(childToParent[front] && !isVisited[childToParent[front]]){
                    flag = true;
                    q.push(childToParent[front]);
                    isVisited[childToParent[front]] = true;
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
        //algo:
        //1. map the childWithParent
        //2 find target node
        //3. burn the aadjacent node and count time

        unordered_map<TreeNode*,TreeNode*> childToParent;
        TreeNode* target = mapAndFindTarget(start,root,childToParent);
        return burn(target,childToParent);
    }
};