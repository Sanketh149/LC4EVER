/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.size())
        {
            int qsize = q.size();
            int first=q.front().second,last=q.back().second;
            for(int i=0;i<qsize;i++)
            {
                long long curr_id = q.front().second; //preventing over flow
                TreeNode *curr = q.front().first;
                q.pop();
                if(curr->left)
                    q.push({curr->left,2*curr_id+1}); //left child index
                if(curr->right)
                    q.push({curr->right,2*curr_id+2}); //right child index
            }
            res = max(res,last-first+1);
        }
        return res;
    }
};