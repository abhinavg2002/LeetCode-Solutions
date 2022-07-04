// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        int n=s.size();
        vector<int> a;
        for(int i=0;i<n;i++){
            if(a.size() and s[i]==')' and s[a.back()]=='('){
                a.pop_back();
                continue;
            }
            a.push_back(i);
        }
        if(a.size()==0){
            return n;
        }
        int lst=n, mx=0;
        while(a.size()){
            int v=a.back();
            a.pop_back();
            mx=max(mx, lst-v-1);
            lst=v;
        }
        mx=max(mx, lst);
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends