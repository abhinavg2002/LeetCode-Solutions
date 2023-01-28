//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    map<pair<string, string>, int> m;
    bool solve(string s1, string s2){
        if(s1==s2)return true;
        if(m.find({s1, s2})!=m.end())return m[{s1, s2}];
        bool flag=false;
        int n=s1.size();
        for(int i=1;i<=n-1;i++){
            bool a1=solve(s1.substr(0, i), s2.substr(n-i)) and solve(s1.substr(i), s2.substr(0, n-i));
            bool a2=solve(s1.substr(0, i), s2.substr(0, i)) and solve(s1.substr(i), s2.substr(i));
            flag=flag or a1 or a2;
            if(flag)return true;
        }
        return m[{s1, s2}]=flag;
    }
    bool isScramble(string s1, string s2){
        m.clear();
        return solve(s1, s2);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends