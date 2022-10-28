class Solution {
public:
    void p(vector<int> o){
        for(auto x:o){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    vector<int> manacher_odd(string s)
    {
        int n = (s.size());
        vector<int> d1(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i)
        {
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
                ++k;
            d1[i] = k;
            if (i + k - 1 > r)
                l = i - k + 1, r = i + k - 1;
        }
        return d1;
    }

    long long maxProduct(string s) {
        int n=s.size();
        auto o=manacher_odd(s);
        vector<int> pr(n), sf(n);
        long long ans=0;
        for(int i=0;i<n;i++){
            pr[i+o[i]-1]=max(pr[i+o[i]-1], 2*o[i]-1);
            sf[i-o[i]+1]=max(sf[i-o[i]+1], 2*o[i]-1);
        }
        // p(o);
        // p(pr);
        // p(sf);
        // "ggbswiymmlevedhkbdhntnhdbkhdevelmmyiwsbgg"
        // chances ye bhi hai 
        for (int i = 1; i < n; ++i) {
            pr[n-1-i] = max(pr[n-1-i], pr[n-i]-2); 
            sf[i] = max(sf[i], sf[i-1]-2); 
        }
        
        for (int i = 1; i < n; ++i) {
            pr[i] = max(pr[i-1], pr[i]); 
            sf[n-1-i] = max(sf[n-1-i], sf[n-i]); 
        }
        for(int i=1;i<n;i++){
            pr[i]=max(pr[i], pr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            sf[i]=max(sf[i], sf[i+1]);
        }
        // p(pr);
        // p(sf);
        for(int i=0;i<n-1;i++){
            ans=max(ans, 1ll*pr[i]*sf[i+1]);
        }
        return ans;
    }
};