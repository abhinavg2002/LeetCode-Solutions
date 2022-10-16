int dp[301][11];
class Solution {
public:
    int n;
    int fun(int i, int d, vector<int>&a){
        if(d==1){
            return *max_element(a.begin()+i, a.end());
        }
        int &ans=dp[i][d];
        if(ans!=-1)return ans;
        ans=INT_MAX;
        int mx=0;
        for(int id=i;id<=n-d;id++){
            mx=max(mx, a[id]);
            ans=min(ans, mx+fun(id+1, d-1, a));
        }
        return ans;
    }
    int minDifficulty(vector<int>& jb, int d) {
        n=jb.size();
        if(d>n)return -1;
        if(d==n){
            return accumulate(jb.begin(), jb.end(), 0ll);
        }
        memset(dp,-1,sizeof(dp));
        return fun(0, d, jb);
    }
};