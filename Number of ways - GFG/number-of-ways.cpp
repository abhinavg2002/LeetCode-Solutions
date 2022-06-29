// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int n){
        // code here
        deque<long long> dp;
        for(int i=0;i<4;i++){
            dp.push_back(1);
        }
        for(int i=4;i<=n;i++){
            long long v=dp.back()+dp.front();
            dp.push_back(v);
            dp.pop_front();
        }
        return dp.back();
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends