// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[505][505];
    int fun(int i, int j, string &s, string &t){
        int n=s.size();
        if(i>=n){
            return 10000;
        }
        if(j>=t.size())return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int k=j;
        for( ; k<t.size(); k++){
            if(t[k]==s[i])break;
        }
        if(k==t.size())return 1;
        return dp[i][j]=min(fun(i+1, j, s, t), 1+fun(i+1, k+1, s, t));
    }
    int shortestUnSub(string s, string t) {
        // code here
        int n=s.size();
        memset(dp, -1, sizeof(dp));
        int ans=fun(0,0,s,t);
        return ans>=10000?-1:ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends