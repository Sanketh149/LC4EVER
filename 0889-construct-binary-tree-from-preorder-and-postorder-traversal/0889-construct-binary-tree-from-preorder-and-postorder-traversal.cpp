class Solution {
    private:
        map<int,int>mp;
        int idx = 0;
public:
    TreeNode* rec(vector<int> &pre, vector<int> &post, int start, int end)
    {
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(pre[idx++]);
        if(start == end or idx == pre.size()) return root;
        int position = mp[pre[idx]];
        root->left = rec(pre, post, start, position);
        root->right = rec(pre, post, position+1, end-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0;i<postorder.size();i++)
            mp[postorder[i]] = i;
        return rec(preorder, postorder, 0, preorder.size()-1);
    }
};