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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        ListNode *curr = head->next;
        while(curr and curr->next)
        {
            odd->next = curr->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
            curr = curr->next;
        }
        odd->next = evenHead;
        return head;
    }
};