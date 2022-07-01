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
    int height(TreeNode* r){
        if(!r)return 0;
        return 1+max(height(r->left), height(r->right));
    }
    void fun(TreeNode* root, int l, int r, vector<vector<string>>&ans, int h){
        if(!root)return;
        int m=l+(r-l)/2;
        ans[h][m]=to_string(root->val);
        fun(root->left, l, m-1, ans, h+1);
        fun(root->right, m+1, r, ans, h+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root);
        int w=(1<<h)-1;
        vector<vector<string>> ans(h, vector<string>(w));
        fun(root, 0, w, ans, 0);
        return ans;
    }
};