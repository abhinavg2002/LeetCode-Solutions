// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define ll long long

int modular_exponentiation(ll a, ll b, ll c){
    if(a==0)return 0;
    if(b==0)return 1;
    ll ans;
    if(b%2==0){
        ll small_ans=modular_exponentiation(a, b/2, c);

        ans=(small_ans*small_ans)%c;
    }
    else{
        ll small_ans=modular_exponentiation(a, b-1, c);
        ans=a%c;
        ans=(ans*small_ans)%c;
    }

    return (int)((ans+c)%c);
}

class Solution {
  public:
    long long karyTree(int k, int m) {
        int mod=1e9+7;
        return modular_exponentiation(k, m, mod);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends