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
     bool isCousins(TreeNode* root, int x, int y) {
		unordered_map<int, pair<int, int>> mp;
		helper(root, 0, -1, mp);
		return mp[x].first == mp[y].first && mp[x].second != mp[y].second;
    }
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& mp) {
    	if (!node) return;
    	mp[node->val] = {depth, parent};
    	helper(node->left, depth + 1, node->val, mp);
    	helper(node->right, depth + 1, node->val, mp);
    }
};