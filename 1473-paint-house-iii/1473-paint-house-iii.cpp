class Solution {
public:
    vector<int>house;
    vector<vector<int>> cost;
    int n, m;
    int dp[105][25][105];
    // i->current hs
    // j is last clr;
    // k is target
    int fun(int i, int j, int k){
        if(i>=m or k<0){
            return k==0?k:1e7+1;
        }
        if(house[i]){// painted last year
            return fun(i+1, house[i], k-(j==house[i]?0:1));
        }
        int &ans=dp[i][j][k];
        if(ans!=-1)return ans;
        int res=1e7+1;
        for(int clr=1;clr<=cost[i].size();clr++){
            res=min(res, cost[i][clr-1]+fun(i+1, clr, k-(j!=clr)));
        }
        return ans=res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->house=houses;
        this->cost=cost;
        this->n=n;
        this->m=m;
        memset(dp, -1, sizeof(dp));
        int ans= fun(0, 0, target);
        return ans>1e7?-1:ans;
    }
};