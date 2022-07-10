class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n+1, 0);
        dp[1]=a[1];
        dp[0]=a[0];
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i - 2], dp[i - 1]) + a[i];
        }
        return dp[n]=min(dp[n-1], dp[n-2]);
    }
};