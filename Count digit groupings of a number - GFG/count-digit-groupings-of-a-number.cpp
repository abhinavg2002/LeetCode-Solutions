// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int dp[105][905];
	int fun(string &s, int id, int ls){
	    int n=s.size();
	    if(id==n){
	        return 1;
	    }
	    if(dp[id][ls]!=-1)return dp[id][ls];
	    int cs=0;
	    int ans=0;
	    for(int i=id;i<n;i++){
	        cs+=(s[i]-'0');
	        if(cs>=ls){
	            ans+=fun(s, i+1, cs);
	        }
	    }
	    return dp[id][ls]=ans;
	}
	int TotalCount(string s){
	    // Code here
	    memset(dp, -1, sizeof(dp));
	    return fun(s, 0, 0);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends