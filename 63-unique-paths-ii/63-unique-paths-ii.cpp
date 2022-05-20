class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(v[0][0]==0)dp[0][0]=1;
    
        for(int k=1;k<m;k++){
            if(v[0][k]==0)dp[0][k]=dp[0][k-1];
        }

        for(int k=1;k<n;k++){
            if(v[k][0]==0)dp[k][0]=dp[k-1][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][j]==0){
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};