class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(0);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        ll mh=0, mw=0;
        for(int i=1;i<hc.size();i++){
            mh=max(mh,(ll) hc[i]-hc[i-1]);
        }
        for(int i=1;i<vc.size();i++){
            mw=max(mw,(ll) vc[i]-vc[i-1]);
        }
        return (mh*mw)%mod;
    }
};