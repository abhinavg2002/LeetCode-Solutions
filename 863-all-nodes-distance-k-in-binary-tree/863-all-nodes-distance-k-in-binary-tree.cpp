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
    map<TreeNode*, TreeNode*> parent;
    set<int> ans;
    unordered_set<int> vis;
    void create(TreeNode* root, TreeNode* par){
        if(root==nullptr)return;
        parent[root]=par;
        create(root->left, root);
        create(root->right, root);
    }
    void fun(TreeNode* root, int k){
        if(root==nullptr or vis.count(root->val))return;
        vis.insert(root->val);
        if(k==0){
            ans.insert(root->val);
            return;
        }
        fun(root->left, k-1);
        fun(root->right, k-1);
        fun(parent[root], k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        create(root, nullptr);
        fun(target, k);
        vector<int> v(ans.begin(), ans.end());
        return v;
    }
};