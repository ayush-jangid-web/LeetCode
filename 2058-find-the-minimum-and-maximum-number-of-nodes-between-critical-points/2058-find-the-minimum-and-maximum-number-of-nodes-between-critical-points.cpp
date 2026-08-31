/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* temp = head->next;
        ListNode* prev = head;
        ListNode* nxt = NULL;
        vector<int>arr;

        int idx = 1;
        while(temp->next != NULL ){
            nxt = temp->next;
            //local maxima
            if((temp->val > nxt->val) && (temp->val > prev->val)){
                arr.push_back(idx);
            }
            //local minima
            else if((temp->val < nxt->val) && (temp->val < prev->val)){
                arr.push_back(idx);
            }
            prev = temp;
            temp = nxt;
            idx++;
        }

        int n = arr.size();
        if(n < 2){
            return {-1,-1};
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=1;i<n;i++){
            mini = min(mini,arr[i]-arr[i-1]);
        }
        maxi = arr[n-1] - arr[0];

        return {mini,maxi};
    }
};