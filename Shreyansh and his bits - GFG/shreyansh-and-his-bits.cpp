//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    #define ll long long
    long long nCr(ll n, ll r) {
        if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
        long long ans = 1;
        int i;
        for(i = 1; i <= r; i++) {
            ans *= n - r + i;
            ans /= i;
        }
    
        return ans;
    }
    long long count(long long x) {
        ll b=__builtin_popcountll(x);
        ll ans=0;
        for(int i=63;i>=1;i--){
            if(i<b)break;
            if(x&(1ll<<i)){
                ans+=(nCr(i, b));
                // cout<<i<<" "<<b<<endl;
                b--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends