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
void dfs(TreeNode* root, vector<pair<int, int>>&v, int l){
    if(!root)return;
    v.push_back({root->val, l});
    dfs(root->left, v, l+1);
    dfs(root->right, v, l+1);
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<pair<int, int>>v;
        dfs(root, v, 0);
        map<int, vector<int>> m;
        for(auto x:v){
            m[x.second].push_back(x.first);
        }
        vector<vector<int>> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};