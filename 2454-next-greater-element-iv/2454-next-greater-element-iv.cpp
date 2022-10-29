class Solution {
public:
    int n;
    vector<int> secondGreaterElement(vector<int>& a) {
        n=a.size();
        vector<int> t(n+1);
        t[n]=n;
        for(int i=n-1;i>=0;i--){
            int p=i+1;
            while(p<n and a[p]<=a[i]){
                p=t[p];
            }
            t[i]=p;
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int p=t[i]+1;
            while(p<n and a[p]<=a[i]){
                p=t[p];
            }
            if(p<n){
                ans[i]=a[p];
            }
        }
        return ans;
    }
};