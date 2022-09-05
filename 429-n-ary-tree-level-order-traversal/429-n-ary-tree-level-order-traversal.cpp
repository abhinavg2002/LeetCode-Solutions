/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    map<int, vector<int>> m;
    void fun(Node*root, int l){
        if(!root)return;
        m[l].push_back(root->val);
        for(auto x:root->children){
            fun(x, l+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        fun(root, 0);
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
    
};