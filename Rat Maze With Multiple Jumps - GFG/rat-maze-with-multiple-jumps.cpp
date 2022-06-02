// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& ans ){
        if(i>=matrix.size() || j>=matrix[0].size())
            return 0;
        if(i==matrix.size()-1 && j==matrix[0].size()-1){
            ans[i][j]=1;
            return 1;
        }
        if(matrix[i][j]==0)
        return 0;
        if(ans[i][j]==1) 
            return 1;
        for(int k=1;k<=matrix[i][j];k++){
           if(dfs(i,j+k,matrix,ans))
            return (ans[i][j]=1);
           if(dfs(i+k,j,matrix,ans))
            return (ans[i][j]=1);
        }
        return 0;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    
	   vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),0));
	   if(dfs(0,0,matrix,ans))
	       return ans;
	   return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends