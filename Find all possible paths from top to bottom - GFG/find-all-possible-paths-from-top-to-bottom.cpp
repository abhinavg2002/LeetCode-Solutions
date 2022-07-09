// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    vector<vector<int> > ans;
    vector<int> path;
    public:
    void dfs(int x,int y,int n, int m, vector<vector<int>> &g){
        if(x>=n || y>=m)
            return;
        if(x==n-1 && y==m-1){
            path.push_back(g[x][y]);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(g[x][y]);
        dfs(x+1,y,n,m,g);
        dfs(x,y+1,n,m,g);
        path.pop_back();
        
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid){
        dfs(0,0,n,m,grid);
        return ans;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends