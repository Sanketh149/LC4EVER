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
    int pairSum(ListNode* head) {
        ListNode* slow  = head, *fast = head;
        //reverse second half and check sum now from mid and beginning
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        while(slow)
        {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        int maxi = 0;
        while(prev)
        {
            maxi = max(maxi, prev->val+head->val);
            prev = prev->next;
            head = head->next;
        }
        return maxi;
    }
};