class Solution {
public:
    int n;
    vector<int> p;
    int dp[1005][105][2];
    int fun(int i, int rem, int hold){
        if(i==n or rem==0){
            return 0;
        }
        int &ans=dp[i][rem][hold];
        if(ans!=-1)return ans;
        // kuch mat kar;
        ans=max(ans, fun(i+1, rem, hold));
        if(hold==1){
            // sell;
            ans=max(ans, p[i]+fun(i+1, rem-1, 0));
        }else{
            // buy
            ans=max(ans, -p[i]+fun(i+1, rem, 1));
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        p=prices;
        n=p.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, k, 0);
    }
};