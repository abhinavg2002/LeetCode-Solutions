//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int n=s.size();
        int m=t.size();
        int j=0, i=0;
        while(j<m){
            if(t[j]>='0' and t[j]<='9'){
                int v=0;
                while(j<m and t[j]>='0' and t[j]<='9'){
                    v=v*10+(t[j]-'0');
                    j++;
                }
                i+=(v-1);
                j--;
            }else{
                if(i<n and s[i]!=t[j])return false;
            }
            i++;
            j++;
        }
        return (i==n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends