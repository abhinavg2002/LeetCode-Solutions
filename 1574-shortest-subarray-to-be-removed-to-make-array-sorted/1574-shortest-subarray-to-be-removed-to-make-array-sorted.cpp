class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n=a.size();
        int i=0, j=n-1;
        while(i+1<n and a[i]<=a[i+1])i++;
        if(i==n-1)return 0;
        while(j>i and a[j]>=a[j-1])j--;
        int l=i, h=j;
        int ans=min(n-l-1, h);
        i=0;
        while(i<=l and j<n){
            if(a[i]<=a[j]){
                ans=min(ans, j-i-1);
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};