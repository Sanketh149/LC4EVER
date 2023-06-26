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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<TreeNode *>q;
        q.push(root);
        bool LtoR = true;
        while(q.size())
        {
            int qsize = q.size();
            vector<int>curr(qsize);
            for(int i=0;i<qsize;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                 //if Left to right normal storing else reverse storing
                int idx = (LtoR)?i:(qsize-i-1);
                curr[idx] = temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            LtoR = !LtoR;
            res.push_back(curr);
        }
        return res;
    }
};