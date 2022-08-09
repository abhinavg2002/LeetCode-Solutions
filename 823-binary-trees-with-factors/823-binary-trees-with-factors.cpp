class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int n;
    map<ll,ll> dp;
    int numFactoredBinaryTrees(vector<int>& a) {
        n=a.size();
        sort(a.begin(), a.end());
        ll ans=0;
        for(int i=0;i<n;i++){
            dp[a[i]]=1;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0){
                    (dp[a[i]]+=(1ll*dp[a[j]]*dp[a[i]/a[j]]))%=mod;
                }
            }
            (ans+=dp[a[i]])%=mod;
        }
        return ans;
    }
};