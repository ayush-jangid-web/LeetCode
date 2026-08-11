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
    int gcd(int a,int b){
        while(b!=0){
            int r = a%b;
            a = b;
            b = r;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* first = head;
        ListNode* second;

        while(first!=NULL && first->next!=NULL){
            second = first->next;

            int data = gcd(first->val,second->val);
            ListNode* temp = new ListNode(data);
            
            first->next = temp;
            temp->next = second;

            first = second;
        }
        return head;
    }
};