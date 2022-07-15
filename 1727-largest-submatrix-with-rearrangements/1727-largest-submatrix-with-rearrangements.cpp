class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(a[i][j]){
                    a[i][j]+=a[i-1][j];
                }else{
                    a[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            sort(a[i].begin(), a[i].end(), greater<int>());
            for(int j=0;j<m;j++){
                ans=max(ans, a[i][j]*(j+1));
            }
        }
        return ans;
    }
};