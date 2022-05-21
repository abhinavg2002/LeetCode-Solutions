class Solution {
public:
    int coinChange(vector<int>& d, int p) {
        vector<int> dp(p+1, 0);
        int n=d.size();
        for(int i=1;i<=p;i++){
            int ans=INT_MAX;
            for(int j=0;j<n;j++){
                if(i>=d[j]){
                    ans=min(ans, dp[i-d[j]]);
                }   
            }
            if(ans==INT_MAX){
                dp[i]=ans;
            }else{
                dp[i]=1+ans;
            }
        }
        if(dp[p]==INT_MAX){
            return -1;
        }
        return dp[p];
    }
};