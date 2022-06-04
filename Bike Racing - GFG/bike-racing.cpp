// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long n, long m, long th, long s[], long a[])
    {
        auto check=[&](long mid){
            long sum=0;
            for(int i=0;i<n;i++){
                long sp=s[i]+a[i]*mid;
                if(sp>=th){
                    sum+=sp;
                }
            }
            return sum<=m;
        };
        long l=0, h=1e9;
        int ans;
        while(l<=h){
            long mid=l+(h-l)/2;
            if(check(mid)){
                l=mid+1;
            }else{
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends