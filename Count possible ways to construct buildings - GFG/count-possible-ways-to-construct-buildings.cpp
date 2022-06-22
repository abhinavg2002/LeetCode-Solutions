// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	#define ll long long
	int TotalWays(int n)
	{
	    // 0 1 1 2 3 5
	    
	    // Code here
	    if(n==1){
	        return 4;
	    }
	    if(n==2){
	        return 9;
	    }
	    ll a=2, b=3;
	    int mod=1e9+7;
	    ll c=0;
	    for(int i=3;i<=n;i++){
	        c=a+b;
	        c%=mod;
	        a=b;
	        b=c;
	    }
	    return (c*c)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends