class Solution {
public:
    #define ll long long
    int maxDistance(vector<int>& p, int m) {
        int n=p.size();
        multiset<int> st(p.begin(), p.end());
        auto check=[&](ll mid){
            ll s=*st.begin();
            ll ct=1;
            s+=mid;
            // basically every pair of magnetic balls ke beech ka forces should be atleast mid
            auto it=st.lower_bound(s);
            while(it!=st.end()){
                s=*it;
                s+=mid;
                it=st.lower_bound(s);
                ct++;
            }
            return ct>=m;
        };
        
        ll l=1, h=1e9+5, ans;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};