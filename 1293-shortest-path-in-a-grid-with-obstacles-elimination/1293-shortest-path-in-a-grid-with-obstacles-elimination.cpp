class Solution {
public:
    const int inf=1e9;
    int n, m, k;
    vector<vector<int>> g, vis;
    int dp[41][41][1601];
    int d[5]={0, 1, 0, -1, 0};
    bool valid(int i, int j){
        return i>=0 and j>=0 and i<n and j<m;        
    }
    int fun(int i, int j, int e){
        if(e>k)return inf;
        if(i==n-1 and j==m-1){
            return 0;
        }
        int &ans=dp[i][j][e];
        if(ans!=-1)return ans;
        ans=inf;
        for(int id=0;id<4;id++){
            int ni=i+d[id];
            int nj=j+d[id+1];
            if(valid(ni, nj)){
                if(g[ni][nj])ans=min({ans, 1+fun(ni, nj, e+1)});
                else ans=min(ans, 1+fun(ni, nj, e));
            }
        }
        return ans;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        g=grid;
        n=g.size(), m=g[0].size();
        // vis=vector<vector<int>>(n, vector<int>(m,0));
        this->k=k;
        memset(dp,-1,sizeof(dp));
        int ans=fun(0,0,0);
        if(ans==inf)ans=-1;
        return ans;
    }
};