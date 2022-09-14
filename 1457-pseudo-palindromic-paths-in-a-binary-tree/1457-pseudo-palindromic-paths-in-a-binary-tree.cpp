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
vector<unordered_map<int, int>> v;
class Solution {
public:
    void fun(TreeNode* root, unordered_map<int, int>& t){
        if(!root){
            // v.push_back(t);
            return;
        }
        if(root->left==NULL and root->right==NULL){
            t[root->val]++;
            v.push_back(t);
            t[root->val]--;
            if(t[root->val]==0){
                t.erase(root->val);
            }
            return;
        }
        t[root->val]++;
        fun(root->left, t);
        fun(root->right, t);
        t[root->val]--;
        if(t[root->val]==0){
            t.erase(root->val);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        v.clear();
        unordered_map<int, int> t;
        fun(root, t);
        int ans=0;
        for(auto x:v){
            int oc=0;
            for(auto p:x){
                if(p.second&1){
                    oc++;
                }
            }
            if(oc<=1){
                ans++;
            }
        }
        return ans;
    }
};