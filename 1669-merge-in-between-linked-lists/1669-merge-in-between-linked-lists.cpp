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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list1;
        int cnta = 1;
        while(cnta!=a){
            tempA = tempA->next;
            cnta++;
        }

        int cntb = -1;
        while(cntb!=b){
            tempB = tempB->next;
            cntb++;
        }
        
        tempA->next = list2;
        ListNode* list2temp = list2;
        while(list2temp->next!=NULL){
            list2temp = list2temp->next;
        }

        list2temp->next = tempB;
        return list1;

    }
};