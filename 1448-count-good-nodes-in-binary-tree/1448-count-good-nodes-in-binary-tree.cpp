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
    int ans=0;
    // int cmax=0;
    void fun(TreeNode* root, int cmax){
        if(!root)return;
        if(root->val>=cmax)ans++;
        cmax=max(cmax, root->val);
        fun(root->left, cmax);
        fun(root->right, cmax);
    }
    int goodNodes(TreeNode* root) {
        int val=-1e5;
        fun(root, val);
        return ans;
    }
};