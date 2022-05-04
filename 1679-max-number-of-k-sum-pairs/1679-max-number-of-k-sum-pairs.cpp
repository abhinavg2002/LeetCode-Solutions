class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n=a.size();
        int i=0, j=n-1;
        int ans=0;
        while(i<j){
            if(a[i]+a[j]==k){
                i++;j--;
                ans++;
            }else {
                if(a[i]+a[j]>k){
                    j--;
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};