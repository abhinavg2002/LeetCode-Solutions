//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string s, int k)
{
    if(k==0)return s;
    int n=s.size();
    if(k>=n)return "0";
    stack<char> st;
    for(auto x:s){
        if(st.size()==0){
            st.push(x);
            continue;
        }
        while(st.size() and st.top()>x and k){
            st.pop();
            k--;
        }
        st.push(x);
    }
    while(st.size() and k--){
        st.pop();
    }
    string ans;
    while(st.size()){
        ans=st.top()+ans;
        st.pop();
    }
    int j=0;
    while(j<ans.size() and ans[j]=='0')j++;
    if(j==ans.size())return "0";
    return ans.substr(j);
}