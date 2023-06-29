class comp{
    public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        priority_queue<ListNode*, vector<ListNode*>, comp>pq;
        int k = lists.size();
        for(int i = 0;i<k;i++)
            if(lists[i] != NULL)
                pq.push(lists[i]);
        while(pq.size())
        {
            auto currNode = pq.top();
            pq.pop();
            curr->next = currNode;
            curr = currNode;
            if(currNode->next)
                pq.push(currNode->next);
        }
        return head->next;
    }
};