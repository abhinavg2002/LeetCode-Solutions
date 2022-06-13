class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<int> dp, pre;
        for(int i=0;i<n;i++){
            dp.resize(t[i].size());
            if(i==0){
                dp[0]=t[0][0];
                pre=dp;
                continue;
            }
            for(int j=0;j<t[i].size();j++){
                if(j>0){
                    if(j==t[i].size()-1){
                        dp[j]=t[i][j]+pre[j-1];
                    }else dp[j]=t[i][j]+min(pre[j], pre[j-1]);
                }else{
                    dp[j]=t[i][j]+pre[j];     
                }
            }
            pre=dp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};