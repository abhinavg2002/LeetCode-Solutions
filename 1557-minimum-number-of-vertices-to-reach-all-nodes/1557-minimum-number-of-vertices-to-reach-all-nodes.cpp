

void dfs(int i, vector<int> &visited, vector<int>l[]){
    visited[i]=1;
    for(auto x:l[i]){
        if(!visited[x]){
            dfs(x, visited, l);
        }
    }
}

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        for(auto x:edges){
            in[x[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!in[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
        
    }
};