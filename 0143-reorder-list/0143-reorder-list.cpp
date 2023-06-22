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
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode *mid = getMid(head);
        ListNode *rev = reverseList(mid->next);
        mid->next = NULL;
        while(head and rev)
        {
            ListNode *nn = head->next, *rn = rev->next;
            head->next = rev;
            head->next->next = nn;
            head = nn;
            rev = rn;
        }
    }
};