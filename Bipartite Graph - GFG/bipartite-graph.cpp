// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool dfs_recurse(int src, vector<int> &visit, vector<int> &color, int c, int v, vector<int>l[]){
    visit[src]=1;
    color[src]=c;

    for(auto x:l[src]){
        if(!visit[x]){
            int ans=dfs_recurse(x, visit, color, !c, v, l);
            if(ans==0)return 0;
        }else{
            if(color[x]==color[src]){
                return 0;
            }
        }
    }
    return 1;

}

bool check(int v, vector<int>adj[]){
    vector<int> visit(v, 0);
    vector<int> color(v, -1);
    int ans=1;
    for(int i=0;i<v;i++){
        if(!visit[i]){
            ans = ans and dfs_recurse(i, visit, color, 1, v, adj);
        }
    }
    return ans;
    
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    return check(V, adj);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends