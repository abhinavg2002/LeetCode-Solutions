class Solution {
public:
    int waysToSplit(vector<int>& a) {
        int n=a.size();
        int mod=1e9+7;
        vector<int>p(n);
        p=a;
        for(int i=1;i<n;i++)p[i]+=p[i-1];
        int s=p[n-1];
        int cs=0;
        long ans=0;
        for(int i=0;i<n-2;i++){
            cs=p[i];
            int mx=(s-cs)/2;
            if(mx<cs)break;
            auto l=lower_bound(p.begin()+i+1, p.end()-1,2*cs);
            auto h=upper_bound(p.begin()+i+1, p.end()-1,cs+mx);
            ans+=(h-l)%mod;
        }
        return ans%mod;
    }
};