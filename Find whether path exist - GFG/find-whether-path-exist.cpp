// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int n, m;
    int d[5]={0, -1, 0, 1, 0};
    bool fun(int i, int j, vector<vector<int>>&g){
        if(i<0 or j<0 or i>=n or j>=m or g[i][j]<=0)return false;
        if(g[i][j]==2)return true;
        g[i][j]=-1;
        for(int k=0;k<4;k++){
            if(fun(i+d[k], j+d[k+1], g))return true;
        }
        return false;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& g) 
    {
        n=g.size(), m=g[0].size();
        int sx, sy, dx, dy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    sx=i, sy=j;
                    break;
                }
            }
        }
        return fun(sx, sy, g);
        //code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends