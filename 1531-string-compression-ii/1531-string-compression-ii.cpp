
int dp[101][101][27][101];
class Solution {
public:
    int n;
    string s;
    const int inf=1e9;
    int fun(int i, int k, int p, int l){
        if(k<0)return inf;
        if(i==n){
            return 0;
        }
        int &ans=dp[i][k][p][l];
        if(ans!=-1)return ans;
        ans=fun(i+1, k-1, p, l);
        if(s[i]-'a'==p){
            int ct=(l==1 or l==9 or l==99);
            ans=min(ans, ct+fun(i+1, k, p, l+1));
        }else{
            ans=min(ans, 1+fun(i+1, k, s[i]-'a', 1));
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        this->s=s;
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return fun(0, k, 26, 0);
    }
};