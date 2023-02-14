//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    #define ll long long
    int n;
    vector<vector<int>> v;
    ll dp[100003][4];
    ll fun(int i, int c){
        if(i==n)return 0;
        ll &ans=dp[i][c];
        if(ans!=-1)return ans;
        ans=1e15;
        for(int id=0;id<3;id++){
            if(id+1==c)continue;
            ans=min(ans, v[i][id]+fun(i+1, id+1));
        }
        return ans;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        n=N;
        v=colors;
        memset(dp,-1,sizeof(dp));
        return fun(0,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends