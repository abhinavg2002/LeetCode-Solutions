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
    TreeNode *f, *s, *l;
    void fun(TreeNode* root){
        if(!root)return;
        fun(root->left);
        if(f==nullptr and l->val>root->val){
            f=l;
        }
        if(f!=nullptr and l->val>root->val){
            s=root;
        }
        l=root;
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        l=new TreeNode(INT_MIN);
        fun(root);
        swap(f->val, s->val);
    }
};