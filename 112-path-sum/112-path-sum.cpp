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
    bool hasPathSum(TreeNode* root, int x) {
        if(root==NULL){
            // if(x==0)return 1;
            return 0;   
        }
        if(!root->left  and !root->right){
            return x==root->val;
        }
        
        x-=root->val;
        return hasPathSum(root->left, x) or hasPathSum(root->right, x);
    }
};