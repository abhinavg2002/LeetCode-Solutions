class Solution {
public:
    #define ll long long
    string s;
    int mod=1e9+7;
    ll dp[1001][1001];
    ll fun(int i, int j){
        if(i==j)return 1;
        if(i>j)return 0;
        ll &ans=dp[i][j];
        if(ans!=-1)return ans;
        ans=0;
        if(s[i]==s[j]){
            (ans=(2ll*fun(i+1, j-1))%mod)%=mod;
            int l=i+1, r=j-1;
            while(l<=r and s[i]!=s[l])l++;
            while(l<=r and s[j]!=s[r])r--;
            if(l<r){
                (((ans-=fun(l+1, r-1))%=mod)+=mod)%=mod;
            }else if(l==r){
                ans++;
            }else{
                ans+=2;
            }
            return ans%mod;
        }
        return ans=(((fun(i+1, j)+fun(i, j-1)-fun(i+1, j-1))%mod+mod))%mod;
    }
    int countPalindromicSubsequences(string s) {
        this->s=s;
        memset(dp,-1,sizeof(dp));
        return fun(0, s.size()-1);
    }
};