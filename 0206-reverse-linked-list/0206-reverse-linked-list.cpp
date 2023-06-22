class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};