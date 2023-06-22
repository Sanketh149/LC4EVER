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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        if(!head or !head->next) return head;
        while(curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        ListNode *mid = getMid(head);
        ListNode *rev = reverseList(mid);
        ListNode *left = head->next;
        int i = 0;
        while(left != rev)
        {
            if(i & 1)
            {
                head->next = left;
                left = left->next;
            }
            else
            {
                head->next = rev;
                rev = rev->next;
            }
            i++;
            head = head->next;
        }
    }
};