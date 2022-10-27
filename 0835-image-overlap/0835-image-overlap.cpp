class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        vector<pair<int,int>> va, vb;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j])va.push_back({i,j});
                if(b[i][j])vb.push_back({i,j});
            }
        }
        map<pair<int,int>,int> m;
        int ans=0;
        for(auto x:va){
            for(auto y:vb){
                int d1=x.first-y.first;
                int d2=x.second-y.second;
                m[{d1, d2}]++;
                ans=max(ans, m[{d1, d2}]);
            }
        }
        return ans;
    }
};