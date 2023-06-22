class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head or !head->next) return head;
        ListNode *dummy = new ListNode(-1), *l = dummy;
        dummy->next = head;
        for(int i =0;i<m-1;i++)
            l = l->next;
        ListNode *curr = l->next, *prev = NULL;
        for(int i = 0;i<n-m+1;i++)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l->next->next = curr;
        l->next = prev;
        return dummy->next;
    }
};