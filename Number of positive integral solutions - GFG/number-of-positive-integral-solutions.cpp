// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
public:
    typedef long long ll;
   
   ll ncr(ll n, ll k){
       ll C[k + 1] = {0};
       C[0] = 1;
       for (ll i = 1; i <= n; i++) 
           for (ll j = min(i, k); j > 0; j--)
               C[j] = C[j] + C[j - 1];
       return C[k];
   }

   long long posIntSol(string s)
   {
       int n = 0, mul = 1;;
       int in = s.size() - 1;
       while(s[in] <= '9' and s[in] >= '0'){
           n = n + (s[in]-'0')*mul;
           mul *= 10;
           --in;
       }
       int r = count(s.begin(), s.end(), '+') + 1;
       n -= r;
       if(n < 0) return 0;
       return ncr(n+r-1, r-1);
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends