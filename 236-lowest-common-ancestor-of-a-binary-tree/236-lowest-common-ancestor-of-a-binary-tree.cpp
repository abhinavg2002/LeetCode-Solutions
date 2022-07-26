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
    bool hasPath(TreeNode *root, vector<TreeNode*>& arr, TreeNode* x)
    {
        if (!root)
            return false;
        arr.push_back(root);   
        if (root == x)   
            return true;
        if (hasPath(root->left, arr, x) || hasPath(root->right, arr, x))
            return true;  
        arr.pop_back();
        return false;           
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b;
        hasPath(root, a, p);
        hasPath(root, b, q);
        int i=0;
        while(i<min(a.size(), b.size()) and a[i]==b[i])i++;
        return a[i-1];
    }
};