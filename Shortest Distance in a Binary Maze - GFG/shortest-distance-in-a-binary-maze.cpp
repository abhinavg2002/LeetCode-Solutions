//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int i=source.first, j=source.second;
        int n=grid.size(), m=grid[0].size();
        int x=destination.first, y=destination.second;
        if(!grid[i][j] || !grid[x][y])return -1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{i,j},0});
        grid[i][j]=0;
        while(!q.empty())
        {
            int c=q.size();
            while(c--)
            {
                auto p=q.front();
                q.pop();
                i=p.first.first, j=p.first.second;
                if(i==x && j==y)
                return p.second;
                if(i+1<n && grid[i+1][j])
                {
                    grid[i+1][j]=0;
                    q.push({{i+1,j},p.second+1});
                }
                if(j+1<m && grid[i][j+1])
                {
                    grid[i][j+1]=0;
                    q.push({{i,j+1},p.second+1});
                }
                if(i-1>=0 && grid[i-1][j])
                {
                    grid[i-1][j]=0;
                    q.push({{i-1,j},p.second+1});
                }
                if(j-1>=0 && grid[i][j-1])
                {
                    grid[i][j-1]=0;
                    q.push({{i,j-1},p.second+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends