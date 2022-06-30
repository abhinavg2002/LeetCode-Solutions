// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int dp[10001];
	int fun(int n){
	    if(n==0)return 0;
	    if(n==1)return 1;
	    if(dp[n]!=-1)return dp[n];
	    int ans=1e9;
	    for(int i=1;i*i<=n;i++){
	        ans=min(ans, 1+fun(n-i*i));
	    }
	    return dp[n]=ans;
	}
	int MinSquares(int n)
	{
	    memset(dp, -1, sizeof(dp));
	    return fun(n);
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends