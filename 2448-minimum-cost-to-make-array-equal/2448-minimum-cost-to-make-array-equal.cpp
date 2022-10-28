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
        
        ll l=1, r=1e6;
        while(r-l>2){
            // cout<<l<<" "<<r<<endl;
            ll m1 = l + (r - l) / 3;
            ll m2 = r - (r - l) / 3;
            ll f1 = f(m1);      //evaluates the function at m1
            ll f2 = f(m2);      //evaluates the function at m2
            if (f1 < f2)
                r = m2;
            else
                l = m1;
        }
        return min({f(l), f(r), f(l+1)});
    }
};