/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void s(TreeNode* root, int n1, vector<TreeNode*> &v){
        if(root==NULL)return;
        v.push_back(root);
        if(root->val==n1){
            return;
        }
        if(root->val<n1){
            s(root->right, n1, v);
        }
        s(root->left, n1, v);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        s(root, p->val, v1);
        s(root, q->val, v2);
        int i=0;
        while(i<min(v1.size(), v2.size()) and v1[i]==v2[i]){
            i++;
        }
        if(i==min(v1.size(), v2.size())){
            if(i==v1.size()){
                return v1[i-1];
            }
            else{
                return v2[i-1];
            }
        }else{
            return v1[i-1];
        }
    }
};