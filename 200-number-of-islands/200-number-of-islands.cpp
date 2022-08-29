bool is(int i, int j, vector<vector<char>>& g, vector<vector<int>> &visit, int n, int m){
    if(i>=0 and j>=0 and i<n and j<m and visit[i][j]==0 and g[i][j]=='1'){
        return true;
    }
    return false;
}

int x[]={-1, 0, 1, 0};
int y[]={0, -1, 0, 1};
void dfs(int i, int j, vector<vector<char>>& g, vector<vector<int>> &visit, int n, int m){
    visit[i][j]=1;
    for(int k=0;k<4;k++){
        if(is(i+x[k], j+y[k], g, visit, n, m)){
            dfs(i+x[k], j+y[k], g, visit, n, m);
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int n=g.size();
        int m =g[0].size();
        vector<vector<int>> visit(n, vector<int> (m, 0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] and g[i][j]=='1'){
                    ans++;
                    dfs(i, j, g, visit, n, m);
                }
            }
        }
        return ans;
    }
};