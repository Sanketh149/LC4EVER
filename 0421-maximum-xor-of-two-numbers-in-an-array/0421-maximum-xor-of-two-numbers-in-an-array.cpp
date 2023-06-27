struct Node{
    Node *links[2];
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
};



class Trie {
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
    public: void insert(int num) {
            Node *curr = root;
            for(int i = 31;i>=0;i--)
            {
                int bit = (num>>i) & 1;
                if(!curr->containsKey(bit))
                {
                    curr->put(bit, new Node());
                }
                curr = curr->get(bit);
            }
        }
    public: int getMax(int num) {
            Node *curr = root;
            int maxNum = 0;
            for(int i = 31;i>=0;i--)
            {
                int bit = (num>>i)&1;
                if(curr->containsKey(1-bit))
                {
                    maxNum = maxNum | (1<<i);
                    curr = curr->get(1-bit);
                }
                else{
                    curr = curr->get(bit);
                }
            }
            return maxNum;
        }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(auto it:nums) root->insert(it);
        int maxNum = 0;
        for(auto it:nums)
            maxNum = max(maxNum, root->getMax(it));
        return maxNum;
    }
};