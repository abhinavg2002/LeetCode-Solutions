//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    #define ll long long
    int n;
    vector<vector<int>> v;
    ll dp[50003][4];
    ll fun(int i, int c){
        if(i==n)return 0;
        ll &ans=dp[i][c];
        if(ans!=-1)return ans;
        ans=1e15;
        for(int id=0;id<3;id++){
            if(id+1==c)continue;
            ans=min(ans, v[i][id]+fun(i+1, id+1));
        }
        return ans;
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        n=N;
        for(int i=0;i<n;i++){
            v.push_back({r[i], g[i], b[i]});
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends