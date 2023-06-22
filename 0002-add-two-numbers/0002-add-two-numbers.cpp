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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *curr = dummy;
        int carry = 0;
        while(l1 or l2 or carry)
        {
            int sum = 0;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode *temp = new ListNode(sum%10);
            curr->next = temp;
            curr = temp;
            if(sum >= 10) carry = 1; 
            else carry = 0;
        }
        return dummy->next;
    }
};