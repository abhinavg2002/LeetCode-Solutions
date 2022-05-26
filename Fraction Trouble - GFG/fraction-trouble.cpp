// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        // p/q such that p*d<=q*n-1;
        int v=__gcd(n, d);
        n/=v;
        d/=v;
        for(int q=10000;q>=1;q--){
            int r=q*n-1;
            if(r%d==0){
                return {r/d, q};
            }
        }
        return {};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends