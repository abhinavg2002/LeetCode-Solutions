//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> fun(int n, vector<vector<pair<int,int>>> &l, int a){
        set<pair<int, int>> s;
        // {dist, start};
        s.insert({0, a});
        vector<int> dis(n, 1e9+10);
        dis[a]=0;
        // stores the predecessors of all vertices
        vector<int> p(n, -1);
        while(s.size()){
            // smallest distance wala node lo
            auto pr=*s.begin();
            int d=pr.first;
            int node=pr.second;
            s.erase(s.begin());
            // uske neighbours ko relax karo
            for(auto nbrPair:l[node]){
                int nbr=nbrPair.first;
                int cost=nbrPair.second;
                if(dis[nbr]>dis[node]+cost){
                    // purana pair agr hai to use hatao
                    auto it=s.find({dis[nbr], nbr});
                    if(it!=s.end()){
                        s.erase(it);
                    }
                    p[nbr]=node;
                    // updated pair ko insert karo
                    dis[nbr]=dis[node]+cost;
                    s.insert({dis[nbr], nbr});
                }
            }
        }
        return dis;
    }
    void p(vector<int> &da){
        for(auto x:da){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        a--, b--;
        
        vector<vector<pair<int,int>>> l(n);
        for(auto x:edges){
            l[x[0]-1].push_back({x[1]-1, x[2]});
            l[x[1]-1].push_back({x[0]-1, x[2]});
        }
        vector<int> da=fun(n, l, a);
        vector<int> db=fun(n, l, b);
        int ans=da[b];
        
        // p(da);
        // p(db);
        for(auto x:edges){
            int u=x[0]-1, v=x[1]-1, w=x[3];
            ans=min({ans, da[u]+db[v]+w, da[v]+db[u]+w});
        }
        if(ans==1e9+10)return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends