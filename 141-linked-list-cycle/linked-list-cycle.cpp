/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head->next ? head->next : nullptr;

        while(fast->next && slow != fast){
            slow = slow->next;
            fast = fast->next;
            if(fast->next) fast = fast->next;
        }

        return fast==slow ? true : false;
    }
};