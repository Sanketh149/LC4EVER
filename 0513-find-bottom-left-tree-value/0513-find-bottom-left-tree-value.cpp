
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr->right != NULL) q.push(curr->right);
            if(curr->left != NULL) q.push(curr->left);
        }
        return curr->val;
    }
};