// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]=0;
        }
        int n=s.size();
        int i=0, j=0, ans=INT_MAX, ct=0;
        while(j<n){
            if(m[s[j]]==0)ct++;
            m[s[j]]++;
            if(ct==m.size()){
                while(i<j and m[s[i]]>1){
                    m[s[i]]--;
                    i++;
                }
                ans=min(ans, j-i+1);
            }
            j++;
        }
        return ans;
        // Your code goes here   
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends