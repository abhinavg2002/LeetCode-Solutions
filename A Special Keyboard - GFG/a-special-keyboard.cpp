// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string a, string b) {
        // code here
        vector<int> f(26,0);
        for(int i=0;i<26;i++){
            f[a[i]-'a']=i;
        }
        int s=0;
        int ans=0;
        for(auto x:b){
            ans+=abs(f[x-'a']-s);
            s=f[x-'a'];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends