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
    ListNode* swapPairs(ListNode* head) {
        if(!head or head->next == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        while(curr and curr->next)
        {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};