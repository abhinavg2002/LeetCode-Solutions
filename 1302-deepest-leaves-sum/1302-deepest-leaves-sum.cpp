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
    map<int, vector<int>> m;
    void fun(TreeNode*root, int d){
        if(!root)return;
        m[d].push_back(root->val);
        fun(root->left, d+1);
        fun(root->right, d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        fun(root, 0);
        auto it=m.end();
        it--;
        vector<int> a=it->second;
        return accumulate(a.begin(), a.end(), 0ll);
    }
};