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
        if(!head or !head->next) return head;
        ListNode *rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        ListNode *mid = slow->next, *start = head;
        while(mid)
        {
            if(mid->val != start->val) return false;
            mid = mid->next;
            start = start->next;
        }
        slow->next = reverseList(slow->next);
        return true;
        
    }
};