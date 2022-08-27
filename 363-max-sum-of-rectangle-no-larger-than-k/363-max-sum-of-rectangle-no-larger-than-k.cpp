class Solution {
public:
    int fun(vector<int>&a, int k){
        int mx=-1e9;
        set<int> s;
        s.insert(0);
        int cs=0;
        for(auto x:a){
            cs+=x;
            auto it=s.lower_bound(cs-k);
            if(it!=s.end()){
                mx=max(mx, cs-*it);
            }
            s.insert(cs);
        }
        return mx;
    }
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int n=a.size(), m=a[0].size();
        int ans=-1e9;
        for(int i=0;i<n;i++){
            vector<int> v(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    v[k]+=a[j][k];
                }
                ans=max(ans, fun(v,k));
            }
        }
        return ans;
    }
};