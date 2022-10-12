//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

string a, b, c;
int dp[101][101][101];
int fun(int i, int j, int k){
    if(i>=a.size() or j>=b.size() or k>=c.size())return 0;
    int &ans=dp[i][j][k];
    if(ans!=-1)return ans;
    ans=max({ans, fun(i+1, j, k), fun(i, j+1, k), fun(i, j, k+1)});
    if(a[i]==b[j] and b[j]==c[k]){
        ans=max(ans, 1+fun(i+1, j+1, k+1));
    }
    return ans;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    a=A, b=B, c=C;
    memset(dp,-1,sizeof(dp));
    return fun(0,0,0);
}