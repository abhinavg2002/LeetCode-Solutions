//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<pair<int,int>>> adj;
    void fun(int s, vector<int> & d, vector<int> & p) {
        int n = adj.size();
        d.assign(n, 1e9);
        p.assign(n, -1);
    
        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            // agr ye old pair hai to kuch mat karo ise or ye hm check karenge agr iska distance or d[v] same nhi hai to ye purana pair hai
            if (d_v != d[v])
                continue;
    
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;
    
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        adj.resize(n);
        for(auto x:flights){
            adj[x[0]-1].push_back({x[1]-1, x[2]});
        }
        vector<int> d(n), p(n);
        fun(k-1, d, p);
        if(count(d.begin(), d.end(), 1e9))return -1;
        return *max_element(d.begin(), d.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends