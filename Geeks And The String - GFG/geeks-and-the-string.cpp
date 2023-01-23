//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char> a;
        for(auto x:s){
            if(!a.size()){
                a.push(x);
            }else{
                if(a.top()==x){
                    a.pop();
                }else{
                    a.push(x);
                }
            }
        }
        string ans;
        while(a.size()){
            ans+=a.top();a.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==0)return "-1";
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends