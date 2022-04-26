class Solution {
public:
    int rangeSum(vector<int>& v, int n, int l, int r) {
        vector<int> a;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=v[j];
                a.push_back(s);
            }
        }
        sort(a.begin(), a.end());
        int mod=1e9+7;
        long s=0;
        // for(auto x:a)cout<<x<<" ";
        // cout<<endl;
        for(int i=l-1;i<=r-1;i++){
            s+=a[i];
        }
        return s%mod;
    }
};