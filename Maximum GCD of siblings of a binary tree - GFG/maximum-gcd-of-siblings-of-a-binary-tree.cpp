// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int n) {
        // code here
        map<int,vector<int>> m;
        for(auto x:arr){
            m[x[0]].push_back(x[1]);
        }
        int mx=0;
        for(auto x:m){
            int g=0;
            if(x.second.size()<=1)continue;
            for(auto y:x.second){
                g=__gcd(g, y);
            }
            mx=max(mx, g);
        }
        return mx;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends