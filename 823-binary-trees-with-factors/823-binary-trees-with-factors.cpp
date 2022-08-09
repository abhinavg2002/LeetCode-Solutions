class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int n;
    map<ll,multiset<ll>> m;
    map<ll,ll> dp;
    ll fun(int root){
        if(m.count(root)==0)return 1;
        if(dp.count(root))return dp[root];
        ll ans=1;
        for(auto x:m[root]){
            ans+=(1ll*fun(x)*fun(root/x));
            ans%=mod;
        }
        return dp[root]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& a) {
        n=a.size();
        unordered_set<int> s(a.begin(), a.end());
        sort(a.begin(), a.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 and s.count(a[i]/a[j])){
                    m[a[i]].insert(a[j]);
                }
            }
        }
        ll ans=0;
        for(auto x:a){
            ans+=fun(x);
            ans%=mod;
        }
        return ans;
    }
};