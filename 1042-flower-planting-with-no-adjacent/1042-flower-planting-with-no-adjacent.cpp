class Solution {
public:
    vector<vector<int>> l;
    vector<int> col, vis;
    void dfs(int src){
        vis[src]=1;
        set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        for(auto x:l[src]){
            if(col[x]){
                s.erase(col[x]);
            }
        }
        col[src]=*s.begin();
        for(auto x:l[src]){
            if(vis[x])continue;
            dfs(x);
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& e) {
        l.resize(n);
        col.resize(n);
        vis=col;
        for(auto x:e){
            l[x[0]-1].push_back(x[1]-1);
            l[x[1]-1].push_back(x[0]-1);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        return col;
    }
};