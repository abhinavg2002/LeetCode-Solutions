#define ll long long
class Solution {
public:
    ll ct, nl;
    vector<vector<int>> t;
    int ml=0;// max_laps
    vector<ll> best, dp;
    ll fun(int l){
        // agr hme bachi laps ek tyre se karli to wha func me ek ct extra add ho jayega to uske lie ye kar rhe hai
        if(l==0)return -ct;
        if(dp[l]!=-1)return dp[l];
        ll ans=INT_MAX;
        for(int i=1;i<=min(l, ml);i++){
            // who takes best of i laps then change and then calculate for rem laps
            ans=min(ans, best[i]+ct+fun(l-i));
        }
        dp[l]=ans;
        return ans;
    }
    int minimumFinishTime(vector<vector<int>>& t, int ct, int nl) {
        this->t=t;
        this->ct=ct;
        this->nl=nl;
        best.assign(1005, INT_MAX);
        dp.assign(1005, -1);
        for(auto x:t){
            ll f=x[0], r=x[1], t=f;
            ll clt=f;// curlaptime
            for(int lap=1;lap<=nl and clt<ct+f;lap++){
                // for succession see if this is the best we can do 
                // for 1st or 2nd or 3rd or lap ith succession
                if(t<best[lap]){
                    best[lap]=t;
                }
                ml=max(ml, lap);
                // compute time for next succession
                // first update r
                clt*=r;
                // time will increase
                t+=clt;
            }
        }
        return fun(nl);
    }
};