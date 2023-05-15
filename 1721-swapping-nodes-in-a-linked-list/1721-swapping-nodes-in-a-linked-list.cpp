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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 1;
        int kbeg = 0, kend = 0;
        ListNode *curr = head;
        while(curr)
        {
            if(n == k) kbeg = curr->val;
            curr = curr->next;
            n++;
        }
        curr = head;
        for(int i = 0;i<n-k-1;i++)
            curr = curr->next;
        kend = curr->val;
        curr = head;
        int ptr = 1;
        while(curr)
        {
            if(ptr == k) swap(curr->val, kend);
            else if(ptr == n-k) swap(curr->val, kbeg);
            curr = curr->next;
            ptr++;
        }
        return head;
    }
};