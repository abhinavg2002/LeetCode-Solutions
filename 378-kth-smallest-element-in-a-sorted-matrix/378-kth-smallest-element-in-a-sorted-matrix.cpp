class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int l=a[0][0], h=a[n-1][n-1];
        auto fun=[&](int m){
            int ct=0;
            for(auto &x:a){
                ct+=(upper_bound(x.begin(), x.end(), m)-x.begin());
            }  
            return ct>=k;
        };
        int ans;
        while(l<=h){
            int m=l+(h-l)/2;
            if(fun(m)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};