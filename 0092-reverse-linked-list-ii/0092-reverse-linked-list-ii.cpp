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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int>num;
        while(temp!=NULL){
            num.push_back(temp->val);
            temp=temp->next;
        }

        int n = num.size();
        reverse(num.begin()+left-1,num.begin()+right);

        temp = head;
        for(int i=0;i<n;i++){
            temp->val = num[i];
            temp = temp->next;
        }
        return head;
    }
};