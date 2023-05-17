
class Solution {
public:
    int depth(TreeNode *root)
    {
        if(!root) return 0;
        int ld = depth(root->left);
        int rd = depth(root->right);
        return 1+max(ld, rd);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL and root->right == NULL) return root->val;
        int lh = depth(root->left);
        int rh = depth(root->right);
        if(lh >= rh)
            return findBottomLeftValue(root->left);
        else return findBottomLeftValue(root->right);
    }
};