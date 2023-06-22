class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next and n == 1) return NULL;
        ListNode *curr = head;
        for(int i = 0;i<n;i++)
            curr = curr->next;
        ListNode *temp = head;
        if(curr == NULL) return temp->next;
        while(curr and curr->next)
        {
            curr = curr->next;
            temp = temp->next;
        }
        ListNode *del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
    }
};