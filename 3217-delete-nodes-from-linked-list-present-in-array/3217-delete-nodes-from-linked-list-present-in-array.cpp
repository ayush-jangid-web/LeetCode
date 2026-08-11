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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        while(head!=NULL && st.find(head->val) != st.end()){
            //delete head
            ListNode* temp = head;
            head = head->next;
            // delete temp;
        }

        ListNode* nxt = NULL;
        ListNode* prev = head;
        ListNode* temp = (head!=NULL)? head->next : NULL;
        while(temp!=NULL){
            int elem = temp->val;
            if(st.find(elem) != st.end()){
                //delete node
                prev->next = temp->next;
                nxt = temp->next;
                delete temp;
                temp = nxt;
            }
            else{
                //move forward
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};