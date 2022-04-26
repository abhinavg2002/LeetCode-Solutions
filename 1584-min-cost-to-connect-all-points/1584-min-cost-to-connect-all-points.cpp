#define pii pair<int, int>
class Solution {
public:
    int dis(vector<int>&a, vector<int>&b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<vector<pair<int, int>>> l(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=dis(p[i], p[j]);
                l[i].push_back({j, d});
                l[j].push_back({i, d});
            }
        }
        int mst=0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> vis(n, 0);
        // to, wt
        pq.push({0, 0});
        while(pq.size()){
            auto node=pq.top();
            pq.pop();
            int to=node.second;
            int wt=node.first;
            if(vis[to])continue;
            vis[to]=1;
            mst+=wt;
            for(auto nbr:l[to]){
                if(!vis[nbr.first])pq.push({nbr.second, nbr.first});
            }
        }
        return mst;
    }
};