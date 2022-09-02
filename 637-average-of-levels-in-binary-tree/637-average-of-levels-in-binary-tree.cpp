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
    map<int, vector<int>> m;
    void fun(TreeNode* root, int l){
        if(!root)return;
        m[l].push_back(root->val);
        fun(root->left, l+1);
        fun(root->right, l+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        fun(root, 0);
        vector<double> v;
        for(auto x:m){
            v.push_back((double)(accumulate(x.second.begin(), x.second.end(), 0.0)/(double)(x.second.size())));
        }
        return v;
    }
};