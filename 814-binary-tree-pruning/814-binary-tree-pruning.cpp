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
    bool fun(TreeNode* root){
        if(!root)return false;
        bool a=fun(root->left), b=fun(root->right);
        if(!a){
            root->left=NULL;
        }
        if(!b)root->right=NULL;
        return a or b or root->val==1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool a=fun(root);
        if(!a)return NULL;
        return root;
    }
};