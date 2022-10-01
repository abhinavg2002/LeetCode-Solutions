#define mod 1000000007
#define ll long long
ll dp[105];
int solve(string &s, int p){
    if(p==s.size())return 1;
    if(s[p]=='0')return 0;
    if(dp[p]!=-1)return dp[p];
    ll num=0, ans=0;
    for(int j=p;j<s.size();j++){
        num=num*10+s[j]-'0';
        if(num<=26 and num>=1LL){
            ans+=solve(s, j+1);
        }
        else{
            break;
        }
    }
    return dp[p]=ans;
}
class Solution {
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        //if(s[0]=='0')return 0;
        return solve(s, 0);
    }
};