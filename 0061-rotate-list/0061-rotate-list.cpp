    
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k == 0)
            return head;
        int len = 1;
        ListNode *curr = head;
        while(curr->next)
        {
            curr = curr->next;
            len++;
        }
        curr->next = head;
        k = k%len;
        k = len-k;
        while(k--)
            curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};