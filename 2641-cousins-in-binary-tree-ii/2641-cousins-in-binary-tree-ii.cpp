class Solution {
public:
    int summ(TreeNode *root)
    {
        int sum = 0;
        if(!root) return 0;
        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;
        return sum;
    }    
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, int>& m) {
    	if(!node) return;
    	m[depth] += node->val;
    	helper(node->left, depth + 1, node->val, m);
    	helper(node->right, depth + 1, node->val, m);
    }
    void rec(TreeNode *root, unordered_map<int, int>& mp, TreeNode *curr, int depth)
    {
        if(!root) return;
        if(root->left)
            curr->left = new TreeNode(mp[depth] - summ(root));
        if(root->right)
            curr->right = new TreeNode(mp[depth] - summ(root));
        rec(root->left, mp, curr->left, depth+1);
        rec(root->right, mp, curr->right, depth+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *curr = new TreeNode(0);
        unordered_map<int,int>mp;
        TreeNode *temp = root;
        helper(temp, 0, -1, mp);
        rec(root, mp, curr, 1);
        return curr;
    }
};