class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n=g.size();
        int done=(1<<n)-1;
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>((1<<n), 0));
        for(int i=0;i<n;i++){
            // since we dont know which node will give best answer so intially push each node in queue
            q.push({i, (1<<i), 0});
            vis[i][1<<i]=1;
        }
        while(q.size()){
            auto v=q.front();
            q.pop();
            int node=v[0];
            int mask=v[1];
            int dis=v[2];
            if(mask==done){
                return dis;
            }
            for(auto x:g[node]){
                int new_mask=(mask|(1<<x));
                if(vis[x][new_mask]==0){
                    q.push({x, new_mask, dis+1});
                    vis[x][new_mask]=1;
                }
            }
        }
        return -1;
    }
};