class Solution {
public:
    vector<vector<int>> l;
    bool dfs(int src, int col, vector<int>&vis, vector<int>&c){
        vis[src]=1;
        c[src]=col;
        
        for(auto x:l[src]){
            if(!vis[x]){
                if(!dfs(x, col^1, vis, c))return false;
            }else{
                if(c[src]==c[x])return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& v) {
        l.resize(n+1);
        for(auto x:v){
            l[x[0]].push_back(x[1]);
            l[x[1]].push_back(x[0]);
        }
        vector<int> vis(n+1, 0);
        vector<int> c(n+1, -1);
        int ans=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ans=ans and dfs(i, 1, vis, c);
            }
        }
        return ans;
    }
};