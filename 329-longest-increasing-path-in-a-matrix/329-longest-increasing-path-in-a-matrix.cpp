int x[]={-1, 0, 1, 0};
int y[]={0, -1, 0, 1};
long long solve(vector<vector<int>>& a, vector<vector<long long>>& dp, int i, int j, int n, int m){   
    if(dp[i][j]!=1)return dp[i][j];
    long long ans=0;
    for(int k=0;k<4;k++){
        int dx=i+x[k];
        int dy=j+y[k];
        if(dx>=0 and dy>=0 and dx<n and dy<m and a[dx][dy]>a[i][j]){
            dp[i][j]=max(dp[i][j],1+solve(a, dp, dx, dy, n, m));
        }
    }
    return dp[i][j];
}


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 1));
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, solve(a, dp, i, j, n, m));
            }
        }
        
        return ans;
    }
};