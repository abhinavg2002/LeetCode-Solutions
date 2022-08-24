class Solution {
public:
    int m;
    vector<int> c;
    int dp[105][105];
    int fun(int l, int r){
        if(l+1==r)return 0;
        int &ans=dp[l][r];
        if(ans!=-1)return ans;
        ans=1e9;
        for(int p=l+1;p<=r-1;p++){
            ans=min(ans, c[r]-c[l]+fun(l, p)+fun(p, r));
        }
        return ans;
    }
    int minCost(int n, vector<int>& a) {
        c=a;
        c.insert(c.begin(), 0);
        c.push_back(n);
        sort(c.begin(), c.end());
        m=c.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, m-1);
    }
};