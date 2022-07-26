class Solution {
public:
    #define ll long long
    long long countExcellentPairs(vector<int>& v, int k) {
        vector<ll> b(32);
        set<int> s(v.begin(), v.end());
        for(auto x:s){
            b[__builtin_popcount(x)]++;
        }
        ll ans=0;
        
        for(int i=0;i<32;i++){
            for(int j=0;j<32;j++){
                if(i+j>=k){
                    ans+=(1ll*b[i]*b[j]);
                }
            }
        }
        
        return ans;
    }
};