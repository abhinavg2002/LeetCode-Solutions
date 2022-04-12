int dfs(int i, vector<int>&a, vector<int>&v, int n){
    if(i>=n or i<0 or v[i])return false;
    v[i]=1;
    if(a[i]==0)return true;
    return dfs(i+a[i], a, v, n) or dfs(i-a[i], a, v, n);
}

class Solution {
public:
    bool canReach(vector<int>& a, int start) {
        int n=a.size();
        vector<int> v(n, 0);
        return dfs(start, a, v, n);
    }
};