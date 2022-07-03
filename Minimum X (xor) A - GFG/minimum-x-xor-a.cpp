// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        vector<int> v(32);
        for(int i=0;i<32;i++){
            v[i]=(a&(1<<i));
        }
        vector<int> ans(32);
        int ct=__builtin_popcount(b);
        for(int i=31;i>=0 and ct;i--){
            if(v[i]){
                ans[i]=1;
                ct--;
            }
        }
        for(int i=0;i<32 and ct;i++){
            if(ans[i])continue;
            ans[i]=1;
            ct--;
        }
        int val=0;
        for(int i=0;i<32;i++){
            if(ans[i])val+=(1ll<<i);
        }
        return val;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends