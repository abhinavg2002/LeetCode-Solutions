class Solution {
public:
    int minimizeArrayValue(vector<int>& a) {
        long long ans=0, n=a.size(), s=0;
        for(long long i=0;i<n;i++){
            s+=a[i];
            ans=max(ans, (s+i)/(i+1));
        }
        return ans;
    }
};