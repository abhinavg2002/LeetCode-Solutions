class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=i+1, y=j+1;
                if(s1[i]==s2[j]){
                    dp[x][y]=1+dp[x-1][y-1];
                }else{
                    dp[x][y]=max(dp[x-1][y], dp[x][y-1]);
                }
            }
        }
        return n+m-2*dp[n][m];
    }
};