class Solution {
public:
    vector<vector<int>> l;
    map<int, unordered_set<int>> m;
    int ans=0;
    void dfs(int src, vector<int>&visit){
        visit[src]=1;
        for(auto x:l[src]){
            if(!visit[x]){
                if(m[src].count(x))ans++;
                dfs(x, visit);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        l.resize(n);
        for(auto x:connections){
            m[x[0]].insert(x[1]);
            l[x[0]].push_back(x[1]);
            l[x[1]].push_back(x[0]);
        }
        vector<int> visit(n, 0);
        dfs(0, visit);
        return ans;
    }
};