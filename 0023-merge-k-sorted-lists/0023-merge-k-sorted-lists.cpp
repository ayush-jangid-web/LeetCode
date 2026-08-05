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
    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        int k = lists.size();
        if (k == 0) {
            return NULL;
        }

        for (int i = 0; i < k; i++) {
            ListNode* temp = lists[i];
            if (temp != NULL) {
                pq.push(temp);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            if (top->next != NULL) {
                pq.push(top->next);
            }
            if (head == NULL) {
                head = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};