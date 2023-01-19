//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int get(int a, int b, int c, int d){
        int ct=0;
        while(a>c){
            a/=2;
            ct++;
        }
        while(b>d){
            b/=2;
            ct++;
        }
        return ct;
    }
    int carpetBox(int A, int B, int C, int D){
        return min(get(A, B, C, D), get(B, A, C, D));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends