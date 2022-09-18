class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        vector<int> l(n), r(n);
        int mx=a[0];
        l[0]=mx;
        for(int i=1;i<n;i++){
            mx=max(mx, a[i]);
            l[i]=mx;
        }
        mx=a[n-1];
        r[n-1]=mx;
        for(int i=n-2;i>=0;i--){
            mx=max(mx, a[i]);
            r[i]=mx;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int d=min(l[i], r[i])-a[i];
            if(d>0)ans+=d;
        }
        return ans;
    }
};