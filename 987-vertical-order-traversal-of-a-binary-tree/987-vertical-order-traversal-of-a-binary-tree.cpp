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
    map<int, map<int, multiset<int>>> m;
    void fun(TreeNode* root, int w, int l){
        if(!root)return;
        m[w][l].insert(root->val);
        fun(root->left, w-1, l+1);
        fun(root->right, w+1, l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        fun(root, 0, 0);
        for(auto &x:m){
            vector<int> t;
            for(auto &y:x.second){
                t.insert(t.end(), y.second.begin(), y.second.end());
            }
            v.push_back(t);
        }
        return v;
    }
};