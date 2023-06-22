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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or head->next == NULL) return NULL;
        ListNode *prev = new ListNode(-1);
        prev->next = head;
        ListNode *slow = prev, *fast = prev;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *todel = slow->next;
        slow->next = slow->next->next;
        delete todel;
        return head;
    }
};