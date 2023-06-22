class Solution {
public:
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *curr = new ListNode(-1);
        ListNode *head = curr;
        while(left and right)
        {
            if(left->val <= right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if(left)
            curr->next = left;
        if(right)
            curr->next = right;
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *slow = head, *fast = head, *temp = head;
        while(fast and fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL; //first half end
        ListNode *first = sortList(head), *second = sortList(slow);
        return merge(first, second);
    }
    
};