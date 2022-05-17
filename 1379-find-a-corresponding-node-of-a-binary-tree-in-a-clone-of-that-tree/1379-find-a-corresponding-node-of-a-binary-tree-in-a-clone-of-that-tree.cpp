/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool hasPath(TreeNode *root, vector<int>& arr, int x)
{

    if (!root)
        return false;
    arr.push_back(root->val);    
    if (root->val == x)    
        return true;
    if (hasPath(root->left, arr, x) || hasPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;            
}
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<int> a;
        bool s=hasPath(original, a, target->val);
        
        for(int i=1;i<a.size();i++){
            if(cloned->right){
                if(cloned->right->val==a[i])cloned=cloned->right;
                else if(cloned->left){
                    if(cloned->left->val==a[i])
                    cloned=cloned->left;
                }
            }
            else if(cloned->left){
                if(cloned->left->val==a[i])
                    cloned=cloned->left;
                else if(cloned->right){
                    if(cloned->right->val==a[i])cloned=cloned->right;
                }
            }
        }
        
        return cloned;
    }
};