class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& r) {
        int n=r.size();
        int l=0, h=n, ans=-1;
        auto check=[&](int mid, string &t){
            int i=0;
            for(int j=0;j<t.size() and i<p.size();j++){
                if(t[j]==p[i])i++;
            }
            return i==p.size();
        };
        while(l<=h){
            string t=s;
            int mid=l+(h-l)/2;
            for(int i=0;i<mid;i++){
                t[r[i]]='*';
            }
            if(check(mid, t)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};