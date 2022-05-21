// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> a){
        //code here
        vector<int> s(n);
        s[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=s[i+1];
            s[i]=min(s[i], a[i]);
        }
        vector<int> ans(n);
        ans[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            int l=i+1, r=n-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(s[m]<a[i]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            if(r==i)ans[i]=-1;
            else ans[i]=r;
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends