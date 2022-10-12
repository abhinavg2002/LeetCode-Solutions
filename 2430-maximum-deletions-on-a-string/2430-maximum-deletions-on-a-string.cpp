class Solution {
public:
    // map<string,int> dp;
    int dp[4005];
    vector<int> solve(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int fun(string &s){
        int n=s.size();
        if(n==0)return 0;
        // if(dp.count(s))return dp[s];
        if(dp[n]!=-1)return dp[n];
        auto a=solve(s);
        int ans=1;
        for(int i=0;i<n;i++){
            if(2*a[i]==(i+1)){
                string t=s.substr(a[i]);
                ans=max(ans, 1+fun(t));
            }
        }
        // return dp[s]=ans;
        return dp[n]=ans;
    }
    int deleteString(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s);
    }
};