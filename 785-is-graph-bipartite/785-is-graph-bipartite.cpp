bool dfs(int src, int c, vector<int> &visit, vector<int> &color, vector<vector<int>> &l){
    visit[src]=1;
    color[src]=c;
    
    for(auto x: l[src]){
        if(!visit[x]){
            int ans=dfs(x, c^1, visit, color, l);
            if(!ans)return false;
        }else{
            if(color[src]==color[x])return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isBipartite(vector<vector<int>>& l) {
        int n=l.size();
        vector<int> color(n, -1);
        vector<int> visit(n, 0);
        int ans=1;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                ans=ans and dfs(i, 1, visit, color, l);
            }
        }
        return ans;
    }
};