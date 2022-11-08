//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    int sum=accumulate(a, a+n, 0);
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
	    for(int i=0;i<=n;i++){
	        dp[i][0]=1;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(j>=a[i-1]){
	                dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    
	    for(int j=sum/2;j>=0;j--){
	        if(dp[n][j]){
	            return sum-2*j;
	        }   
	    }
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends