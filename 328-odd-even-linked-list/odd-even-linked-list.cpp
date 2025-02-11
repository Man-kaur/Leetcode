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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* oHead = head;
        ListNode* eHead = oHead->next;

        ListNode* optr = oHead;
        ListNode* eptr = eHead;

        while(optr->next && eptr->next){
            optr->next = eptr->next;
            optr = optr->next;

            eptr->next = optr->next;
            eptr = eptr->next;
        }

        optr->next = eHead;

        return oHead;
    }
};