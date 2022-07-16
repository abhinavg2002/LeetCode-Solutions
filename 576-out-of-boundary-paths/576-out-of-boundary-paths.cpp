long dp[55][55][55];
#define mod 1000000007
class Solution {
public:
    int n, m;
    long fun(int i, int j, int move){
        if(i<0 or j<0 or i>=n or j>=m)return 1;
        if(move<=0)return 0;
        if(dp[i][j][move]!=-1)return dp[i][j][move];
        long ans=0;
        ans+=(fun(i+1, j, move-1)+fun(i, j+1, move-1)+fun(i-1, j, move-1)+fun(i, j-1, move-1))%mod;
        return dp[i][j][move]=ans%mod;
    }
    int findPaths(int M, int N, int maxMove, int i, int j) {
        memset(dp, -1, sizeof(dp));
        n=M;
        m=N;
        return fun(i, j, maxMove);
    }
};