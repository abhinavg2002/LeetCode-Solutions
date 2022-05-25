class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int n=v.size();
        auto cmp=[](vector<int>&a, vector<int>&b){
            return a[0]==b[0]?b[1]<a[1]:a[0]<b[0];  
        };
        sort(v.begin(), v.end(), cmp);
        vector<int>dp;
        for(auto &x:v){
            auto it=lower_bound(dp.begin(), dp.end(), x[1]);
            if(it==dp.end()){
                dp.push_back(x[1]);
            }else{
                dp[it-dp.begin()]=x[1];
            }
        }
        return dp.size();
    }
};