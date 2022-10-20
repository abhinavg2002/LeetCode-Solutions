//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&v)  {
        vector<int> a;
        int r=0, c=0;
        int mr=n-1, mc=m-1;
        int ct=0;
        int t=n*m;
        while(ct<n*m){
            for(int j=c, i=r;j<=mc and ct<t;j++)a.push_back(v[i][j]), ct++;
            r++;
            for(int i=r, j=mc;i<=mr and ct<t;i++)a.push_back(v[i][j]), ct++;
            mc--;
            for(int j=mc, i=mr;j>=c and ct<t;j--)a.push_back(v[i][j]), ct++;
            mr--;
            for(int i=mr, j=c;i>=r and ct<t;i--)a.push_back(v[i][j]), ct++;
            c++;
        }
        reverse(a.begin(), a.end());
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends