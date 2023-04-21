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
    int pairs = 0;
    vector<int> dfs(TreeNode *root, int distance)
    {
        if(!root) return {};
        auto left = dfs(root->left, distance);
        auto right = dfs(root->right, distance);
        vector<int>res;
        if(left.size() == 0 and right.size() == 0) // leaf node
        {
            res.push_back(1); //returning that it is at dist 1 from root
            return res;
        }
        for(int i = 0;i<left.size();i++)
        {
            for(int j = 0;j<right.size();j++)
            {
                if(left[i]+right[j] <= distance) pairs++;
            }
        }
        for(auto it:left) res.push_back(it+1); //increase 1 and send to its root
        for(auto it:right) res.push_back(it+1);
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return pairs;
    }
};