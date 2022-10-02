#define mod 1000000007
class Solution {
public:
    long dp[35][1005];
    int fun(int d, int f, int x){
        if(d==0){
            if(x==0)return 1;
            return 0;
        }
        if(x<=0)return 0;
        if(dp[d][x]!=-1)return dp[d][x];
        long ans=0;
        for(int i=1;i<=f;i++){
            ans+=fun(d-1, f, x-i)%mod;
        }
        return dp[d][x]=ans%mod;
    }
    int numRollsToTarget(int d, int f, int target) {
        memset(dp, -1, sizeof(dp));
        return fun(d, f, target);
    }
};