class Solution {
public:
    int mod=1e9+7;
    #define ll long long
    int maxSum(vector<int>& a, vector<int>& b) {
        int n=a.size(), m=b.size();
        int i=0, j=0;
        ll ans=0, sa=0, sb=0;
        while(i<n and j<m){
            if(a[i]<b[j]){
                sa+=(ll)a[i++];
            }else if(a[i]>b[j]){
                sb+=(ll)b[j++];
            }else{
                ans+=(ll)max(sa, sb)+(ll)a[i];
                sa=sb=0;
                i++;j++;
            }
        }
        while(i<n){
            sa+=(ll)a[i++];
        }
        while(j<m){
            sb+=(ll)b[j++];
        }
        ans+=(ll)max(sa, sb);
        return ans%mod;
    }
};