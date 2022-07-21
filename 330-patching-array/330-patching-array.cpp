class Solution {
public:
    #define ll long long
    int minPatches(vector<int>& a, int s) {
        sort(a.begin(), a.end());
        ll res = 1;
        int ct=0;
        for (ll x: a) {
            while(x>res){
                ct++;
                res+=res;
                if(res>s)break;                
            }
            res+=x;
            if(res>s)break;
        }
        while(res<=s){
            res<<=1ll;
            ct++;
        }
        return ct;
    }
};