class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> l;
        for(auto x:roads){
            l[x[0]].insert(x[1]);
            l[x[1]].insert(x[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int v=l[i].size()+l[j].size();
                if(l[i].count(j)){
                    v--;
                }
                ans=max(ans, v);
            }
        }
        return ans;
    }
};