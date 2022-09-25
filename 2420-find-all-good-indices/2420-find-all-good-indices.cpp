class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n=a.size();
        vector<int> p(n), s(n);
        p[0]=1, s[n-1]=1;
        for(int i=1;i<n;i++){
            if(a[i]<=a[i-1])p[i]=p[i-1]+1;
            else p[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]<=a[i+1])s[i]=s[i+1]+1;
            else s[i]=1;
        }
        // for(auto x:p){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:s){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        vector<int> ans;
        
        for(int i=k;i<n-k;i++){
            if(p[i-1]>=k and s[i+1]>=k){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};