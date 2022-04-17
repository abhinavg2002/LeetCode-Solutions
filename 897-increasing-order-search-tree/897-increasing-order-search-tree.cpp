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
void le(TreeNode* root, vector<int>&v){
    if(root==NULL)return;
    
    le(root->left, v);
    v.push_back(root->val);
    le(root->right, v);
    
}
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)return root;
        vector<int> v;
        le(root, v);
        TreeNode* root1=new TreeNode(v[0]);
        TreeNode* temp=root1;
        for(int i=1;i<v.size();i++){
            temp->right=new TreeNode(v[i]);
            temp=temp->right;
        }
        return root1;
    }
};