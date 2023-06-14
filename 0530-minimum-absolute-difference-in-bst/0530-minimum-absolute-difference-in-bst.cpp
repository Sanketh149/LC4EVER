class Solution {
public:
    int mini = 1e9;
    TreeNode *prev;
    void rec(TreeNode *root)
    {
        if(!root) return;
        rec(root->left);
        if(prev) mini = min(mini, root->val - prev->val);
        prev = root;
        rec(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        rec(root);
        return mini;
    }
};