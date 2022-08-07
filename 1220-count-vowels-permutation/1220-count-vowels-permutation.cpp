class Solution {
public:
    int mod=1e9+7;
    long dp[20005][6];
    char a[5]={'a', 'e', 'i', 'o', 'u'}; 
    unordered_map<char, int> m;
    long fun(int i, int n, char last){
        if(i==n)return 1;
        if(dp[i][m[last]]!=-1)return dp[i][m[last]];
        long ans=0;
        if(last=='a'){
            ans+=fun(i+1, n, 'e')%mod;
        }else if(last=='e'){
            ans+=(fun(i+1, n, 'a')+fun(i+1, n, 'i'))%mod;
        }else if(last=='i'){
            for(int k=0;k<5;k++){
                if(a[k]=='i')continue;
                ans+=fun(i+1, n, a[k])%mod;
            }
        }else if(last=='o'){
            ans+=(fun(i+1, n, 'i')+fun(i+1, n, 'u'))%mod;
        }else if(last=='u'){
            ans+=fun(i+1, n, 'a')%mod;
        }
        return dp[i][m[last]]=ans%mod;
    }
    
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<5;i++){
            m[a[i]]=i;
        }
        long ans=0;
        for(int i=0;i<5;i++){
            ans+=fun(1, n, a[i])%mod;
        }
        return ans%mod;
    }
};