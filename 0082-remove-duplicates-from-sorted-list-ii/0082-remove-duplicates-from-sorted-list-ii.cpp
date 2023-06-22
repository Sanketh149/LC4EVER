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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *dummy = new ListNode(101);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = dummy;
        while(curr)
        {
            ListNode *ptr = curr;
            while(ptr->next and ptr->val == ptr->next->val) ptr = ptr->next;
            if(ptr == curr)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = ptr->next;
                curr = ptr->next;
            }
        }
        return dummy->next;
    }
};