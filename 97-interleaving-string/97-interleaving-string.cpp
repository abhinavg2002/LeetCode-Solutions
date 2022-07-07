class Solution {
public:
    int dp[105][105];
    bool fun(string &s1,string &s2,string &s3,int i,int j,int k){
        int a=s1.size();        
        int b=s2.size();
        int c=s3.size();
        if(i>a or j>b or k>c)return false;
        if(i==a and j==b and k==c)return true;
        
        if(dp[i][j]!=-1)return dp[i][j];
        bool res=false;
        if(i<a and k<c and s1[i]==s3[k]){
            res |= fun(s1, s2, s3, i+1, j, k+1);
        }
        if(j<b and k<c and s2[j]==s3[k]){
            res |= fun(s1, s2, s3, i, j+1, k+1);
        }
        return dp[i][j]=res;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size();        
        int b=s2.size();
        int c=s3.size();
        if(c!=a+b)return false;
        memset(dp, -1, sizeof(dp));
        return fun(s1, s2, s3, 0, 0, 0);
    }
};