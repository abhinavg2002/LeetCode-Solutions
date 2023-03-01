//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> updateQuery(int n,int q,vector<vector<int>> &u){
        vector<vector<int>> a(n+1, vector<int>(32,0));
        for(auto e:u){
            int l=e[0]-1;
            int r=e[1]-1;
            int x=e[2];
            for(int b=0;b<32;b++){
                if(x&(1<<b)){
                    a[l][b]++;
                    a[r+1][b]--;
                }
            }
        }
        for(int i=1;i<a.size();i++){
            for(int j=0;j<32;j++){
                a[i][j]+=a[i-1][j];
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int e=0;
            for(int j=0;j<32;j++){
                if(a[i][j]){
                    e+=(1<<j);
                }
            }
            ans[i]=e;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends