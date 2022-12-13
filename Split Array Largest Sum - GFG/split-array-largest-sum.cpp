//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int a[] ,int n, int k) {
        // code here
        auto check=[&](int m)->bool{
            int s=0, mx=0, ct=1;
            for(int i=0;i<n;i++){
                int x=a[i];
                if(s+x<=m){
                    s+=x;
                }else{
                    s=x;ct++;
                    if(s>m)return false;
                }
            }
            return ct<=k;
        };
        int l=0, h=1e9+5, ans;
        while(l<=h){
            int m=l+(h-l)/2;
            // cout<<m<<" "<<check(m)<<endl;
            if(check(m)){
                h=m-1;
                ans=m;
            }else{
                l=m+1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends