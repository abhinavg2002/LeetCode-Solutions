// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

bool dfs_re(int src, vector<vector<int>> &l, vector<bool> &visit, vector<int>&st, list<int> &order){
    visit[src]=1;
    st[src]=1;
    //bool ans=false;
    for(auto x:l[src]){
        if(st[x]){
            return true;
        }
        if(not visit[x]){
            bool ans=dfs_re(x, l, visit, st, order);
            if(ans)return true;
        }
    }
    order.push_front(src);
    st[src]=0;
    return false;
}

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> a) 
    {
        vector<vector<int>> l(n);
        for(auto x:a){
            l[x[1]].push_back(x[0]);
        }
        list<int> order;
        vector<int> st(n, 0);
        vector<bool> visit(n, false);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                if(dfs_re(i, l, visit, st, order)){
                    ans=false;
                }
            }
        }
        if(ans==false)return {};
        else{
            vector<int> v;
            for(auto x:order){
                v.push_back(x);
            }
            return v;
        }
        return {};
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends