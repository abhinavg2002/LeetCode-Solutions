class Solution {
public:
    vector<vector<int>> l, a;
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        l.resize(n);
        vector<vector<int>> a(n, vector<int>(n, 0));
        for(auto &x:edges){
            x[0]--;
            x[1]--;
            l[x[0]].push_back(x[1]);
            l[x[1]].push_back(x[0]);
            a[x[0]][x[1]]=1;
            a[x[1]][x[0]]=1;
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<l[i].size();j++){
                for(int k=j+1;k<l[i].size();k++){
                    int x=l[i][j], y=l[i][k];
                    if(a[x][y]){
                        ans=min(ans,(int) (l[i].size()+l[x].size()+l[y].size()-6));
                    }
                }
            }
        }
        return ans==1e9?-1:ans;
    }
    
};