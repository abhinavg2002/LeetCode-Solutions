class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        int st=0, mx=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                st=i, mx=2;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] and s[i]==s[j]){
                    dp[i][j]=true;
                    if(mx<k){
                        mx=k, st=i;
                    }
                }
            }
        }
        return s.substr(st, mx);
    }
};