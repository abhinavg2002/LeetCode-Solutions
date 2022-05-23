class Solution {
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        vector<pair<int,int>> v;
        for(auto x:s){
            int z=0, o=0;
            for(auto y:x){
                if(y=='0')z++;
                else o++;
            }
            v.push_back({z,o});
        }
        vector<vector<int>>dp(m+1, vector<int>(n+1));
        for(auto &x:v){
            int z=x.first, o=x.second;
            for(int i=m;i>=z;i--){
                for(int j=n;j>=o;j--){
                    dp[i][j]=max(dp[i][j], 1+dp[i-z][j-o]);
                }
            }
        }
        return dp[m][n];
    }
};