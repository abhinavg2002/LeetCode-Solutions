class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int res=0;
    int fun(int i, int j, vector<int>&a, vector<int>&b){
        if(i==n or j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        fun(i+1, j, a, b);
        fun(i, j+1, a, b);
        if(a[i]==b[j]){
            ans=1+fun(i+1, j+1, a, b);
        }
        res=max(res, ans);
        return dp[i][j]=ans;
    }
    int findLength(vector<int>& a, vector<int>& b) {
        n=a.size();
        m=b.size();
        memset(dp, -1, sizeof(dp));
        fun(0,0,a,b);
        return res;
    }
};