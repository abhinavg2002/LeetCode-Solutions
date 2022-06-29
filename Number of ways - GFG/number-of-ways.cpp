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
        for(int i=0;i<=n;i++){
            if(i<4){
                dp.push_back(1);
            }else{
                dp.push_back(dp.back()+dp.front());
                dp.pop_front();
            }
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