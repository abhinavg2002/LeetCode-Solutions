// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 
const int N=1e5+1;
class Solution{
  public:
    // s : given string
    // return the expected answer
    int mod=1e9+7;
    #define ll long long
    
    ll dp[N][4];
    ll get(string &s, int i, int ct){
        if(i==s.size()){
            return ct==3;
        }
        if(dp[i][ct]!=-1)return dp[i][ct];
        ll ans=0;
        if(s[i]==ct+'a'){
            ans+=(get(s, i+1, ct+1)+(2ll*get(s, i+1, ct)));
        }else{
            ans+=get(s, i+1, ct);
        }
        ans%=mod;
        return dp[i][ct]=ans%mod;
    }
    int fun(string &s) {
        //code here
        memset(dp, -1, sizeof(dp));
        return get(s, 0, 0);
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends