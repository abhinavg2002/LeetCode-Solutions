class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& a, vector<int>& cost) {
        int n=a.size();
        auto f=[&](ll m)->ll{
            ll ans=0;
            for(int i=0;i<n;i++){
                ans+=(1ll*abs(a[i]-m)*cost[i]);
            }
            return ans;
        };
        
        ll l=1, r=1e6, ans=1e18;
        while(l<r){
            ll m=l+(r-l)/2;
            ll f1=f(m), f2=f(m+1);
            ans=min({ans, f1, f2});
            if(f1<f2){
                r=m;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};