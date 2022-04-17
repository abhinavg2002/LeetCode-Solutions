class Solution {
public:
    #define ll long long
    ll dp[3005][4][305];
    int mod=1e9+7;
    ll fun(int i, int l, int t, vector<int>&a){
        if(t<0)return 0;
        if(l>3)return 0;
        if(i==a.size()){
            return t==0 and l==3;
        }
        if(dp[i][l][t]!=-1)return dp[i][l][t];
        return dp[i][l][t]=(fun(i+1, l+1, t-a[i], a)+fun(i+1, l, t, a))%mod;
    }
    
    int threeSumMulti(vector<int>& a, int target) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, target, a);
    }
};