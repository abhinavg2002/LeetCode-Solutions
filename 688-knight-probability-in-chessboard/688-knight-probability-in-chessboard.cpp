class Solution {
public:
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int n;
    double dp[30][30][101];
    double fun(int i, int j, int k){
        if(i<0 or j<0 or i>=n or j>=n){
            return 0;
        }
        if(k==0)return 1;
        if(dp[i][j][k])return dp[i][j][k];
        double ans=0;
        for(int id=0;id<8;id++){
            ans+=fun(i+dx[id], j+dy[id], k-1);
        }
        double res=ans/8.0;
        dp[i][j][k]=res;
        return res;
    }
    double knightProbability(int n, int k, int row, int column) {
        this->n=n;
        // memset(dp,-1,sizeof(dp));
        double ans=fun(row, column, k);
        return ans;
    }
};