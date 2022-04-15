#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& p, int hr) {
        auto check=[&](int mid){
            int ct=0;
            for(auto x:p){
                if(x<=mid){
                    ct++;
                }else{
                    int d=x/mid;
                    if(x%mid)d++;
                    ct+=d;
                }
            }
            return ct<=hr;
        };
        
        ll l=1, h=1e10;
        ll ans;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(check(mid)){
                h=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};