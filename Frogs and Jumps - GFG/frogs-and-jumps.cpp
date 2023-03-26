//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int l, int f[]) {
        vector<int> v(l+1,0);
        map<int,int> m;
        for(int i=0;i<n;i++){
            int j=f[i];
            if(j==1)return 0;
            if(m.count(j))continue;
            m[j]++;
            for(int k=j;k<=l;k+=j){
                v[k]++;
            }
        }
        return count(v.begin(), v.end(), 0)-1;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends