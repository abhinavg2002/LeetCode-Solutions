class Solution {
public:
    long dp[35];
    long fun(int n){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fun(n-1)+fun(n-2);
    }
    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        return fun(n);
    }
};