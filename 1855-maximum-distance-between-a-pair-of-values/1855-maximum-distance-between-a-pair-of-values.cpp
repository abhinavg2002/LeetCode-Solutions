class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int i=0, j=0;
        int ans=0;
        while(i<n and j<m){
            if(a[i]>b[j]){
                i++;
            }else{
                ans=max(ans, j-i);
                j++;
            }
        }
        return ans;
    }
};