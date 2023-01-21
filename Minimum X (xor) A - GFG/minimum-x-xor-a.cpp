//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int ans=0;
        int ct=__builtin_popcount(b);
        for(int i=31;i>=0 and ct;i--){
            if(a&(1<<i)){
                ct--;
                ans|=(1<<i);
            }
        }
        if(!ct)return ans;
        for(int i=0;i<32 and ct;i++){
            if(!(a&(1<<i))){
                ct--;
                ans|=(1<<i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends