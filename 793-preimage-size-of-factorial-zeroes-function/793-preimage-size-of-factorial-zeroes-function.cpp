class Solution {
public:
    #define ll long long
    ll fun(ll n){
        if (n < 0)
            return -1;
        ll count = 0;
        for (ll i = 5; (n / i) >= 1; i *= 5ll)
            count += (n / i);
        return count;
    }
    ll bs(int k){
        ll l=0, h=1e10;
        ll ans;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(fun(mid)<=k){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
    int preimageSizeFZF(int k) {
        // max number with k 0-max number with k-1
        if(k==0)return 5;
        return bs(k)-bs(k-1);
    }
};