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
    int fun(TreeNode* root, bool mon, bool cam){
        if(!root){
            return 0;
        }
        if(cam){
            return 1+fun(root->left, 1, 0)+fun(root->right, 1, 0);
        }
        if(mon){
            return min(1+fun(root->left, 1, 0)+fun(root->right, 1, 0), fun(root->left, 0, 0)+fun(root->right, 0, 0));
        }
        if(root->val){
            return root->val;
        }
        int curcam=1+fun(root->left, 1, 0)+fun(root->right, 1, 0);
        int leftcam=root->left?fun(root->left, 0, 1)+fun(root->right, 0, 0):INT_MAX;
        int rightcam=root->right?fun(root->left, 0, 0)+fun(root->right, 0, 1):INT_MAX;
        return root->val=min({curcam, leftcam, rightcam});
    }
    int minCameraCover(TreeNode* root) {
        return fun(root, 0, 0);
    }
};