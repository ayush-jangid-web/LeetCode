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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp->next != NULL && temp->next->next != NULL) {
            ListNode* first = temp->next;
            ListNode* second = temp->next->next;

            first->next = second->next;
            second->next = first;

            temp->next = second;
            temp = first;
        }

        return dummy->next;
    }
};