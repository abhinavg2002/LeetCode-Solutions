class Solution {
public:
    int n;
    vector<int> p;
    int ps;
    int dp[31][31];
    int fun(int i, int j){
        if(i>=j)return 0;
        int &ans=dp[i][j];
        if(ans!=-1)return ans;
        ans=1e9;
        for(int k=i;k<j;k+=(ps-1)){
            ans=min(ans, fun(i,k)+fun(k+1, j));
        }
        if((j-i)%(ps-1)==0){
            ans+=p[j]-(i?p[i-1]:0);
        }
        return ans;
    }
    int mergeStones(vector<int>& s, int k) {
        p=s;
        ps=k;
        n=s.size();
        memset(dp,-1,sizeof(dp));
        if((n-1)%(k-1))return -1;
        for(int i=1;i<n;i++){
            p[i]+=p[i-1];
        }
        return fun(0,n-1);
    }
};