class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int n, m, k;
    vector<vector<int>>g;
    vector<vector<vector<ll>>> dp;
    ll fun(int i, int j, int s){
        if(i<0 or j<0 or i>=n or j>=m)return 0;
        (s+=g[i][j])%=k;
        if(i==n-1 and j==m-1){
            return s==0;
        }
        if(dp[i][j][s]!=-1)return dp[i][j][s];
        return dp[i][j][s]=(fun(i+1, j, s)+fun(i, j+1, s))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        g=grid;
        n=g.size(), m=g[0].size(), this->k=k;
        dp=vector<vector<vector<ll>>>(n,vector<vector<ll>>(m,vector<ll>(51,-1)));
        return fun(0,0,0);
    }
};