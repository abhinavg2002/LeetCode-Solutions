class Solution {
public:
    int uniquePaths(int m, int n) {
        // (n+m-2)C(n-1)
        // (n+m-2)*(n+m-3)....(m-1)/(m-1)!;
        long ans=1;
        int s=n-1;
        for(int i=1;i<=s;i++){
            ans=ans*1ll*(n+m-2-s+i)/i;
        }
        return ans;
    }
};