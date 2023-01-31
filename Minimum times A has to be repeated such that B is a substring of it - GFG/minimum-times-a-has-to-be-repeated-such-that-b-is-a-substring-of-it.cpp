//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        string s="",t="";
        int ct=0;
        while(s.size()<b.size()){
            s+=a;
            ct++;
        }
        t=s+a;
        if(s.find(b)!=string::npos)return ct;
        if(t.find(b)!=string::npos)return ct+1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends