// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int MaxGold(vector<vector<int>>&a){
        // Code here
        int n=a.size();
        int m=a[0].size();
        vector<vector<long long>> dp(n, vector<long long> (m, -1));
        long long ans=0;
        for(int i=0;i<m;i++){
            dp[0][i]=a[0][i];
            ans=max(ans, dp[0][i]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==-1){
                    continue;
                }
                long long r=-1;
                if(j-1>=0 and dp[i-1][j-1]!=-1){
                    r=max(r, dp[i-1][j-1]);
                }
                if(j>=0 and dp[i-1][j]!=-1){
                    r=max(r, dp[i-1][j]);
                }
                if(j+1<m and dp[i-1][j+1]!=-1){
                    r=max(r, dp[i-1][j+1]);
                }
                if(r!=-1)dp[i][j]=a[i][j]+r;
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends