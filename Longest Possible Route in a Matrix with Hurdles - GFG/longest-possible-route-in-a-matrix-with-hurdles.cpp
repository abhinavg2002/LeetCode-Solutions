// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int n, m;
    int vis[15][15];
    int nt[15][15];
    int x, y;
    int fun(int i, int j){
        if(i<0 or j<0 or i>=n or j>=m or nt[i][j] or vis[i][j])return INT_MIN;
        if(i==x and j==y){
            return 0;
        }
        vis[i][j]=1;
        int ans=1+max({fun(i+1, j), fun(i, j+1), fun(i-1, j), fun(i, j-1)});
        vis[i][j]=0;
        return ans;
    }
    int longestPath(vector<vector<int>> v, int xs, int ys, int xd, int yd)
    {
        n=v.size(), m=v[0].size();
        memset(vis, 0, sizeof(vis));
        memset(nt, 0, sizeof(nt));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    nt[i][j]=1;
                }
            }
        }
        x=xd, y=yd;
        int ans=fun(xs,ys);
        return ans<0?-1:ans;
        // code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends