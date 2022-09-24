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
vector<vector<int>> v;
void solve(TreeNode* root, vector<int>&t, int sum, int x){
    if(root==nullptr)return;
    if(root->left == nullptr and root->right == nullptr){
        t.push_back(root->val);
        sum+=root->val;
        if(sum==x){
            v.push_back(t);
        }
        t.pop_back();
        return;
    }
    t.push_back(root->val);
    sum+=root->val;
    if(root->left){
        solve(root->left, t, sum, x);
    }
    if(root->right){
        solve(root->right, t, sum, x);
    }
    t.pop_back();
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        v.clear();
        vector<int> t;
        solve(root, t, 0, targetSum);
        return v;
    }
};