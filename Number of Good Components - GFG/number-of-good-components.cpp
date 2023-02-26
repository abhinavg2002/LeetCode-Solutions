//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void fun(int p, vector<vector<int>>&l, vector<int> &vis, vector<int>&c){
        vis[p]=1;
        c.push_back(p);
        for(auto x:l[p]){
            if(!vis[x])fun(x, l, vis, c);
        }
    }
    int findNumberOfGoodComponent(int n, vector<vector<int>>& l) {
        int ct=0;
        vector<int> vis(n+1);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int> c;
                fun(i, l, vis, c);
                int s=c.size();
                int e=0;
                for(auto x:c){
                    e+=l[x].size();
                }
                e/=2;
                int t=(s*(s-1))/2;
                ct+=(t==e);
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends