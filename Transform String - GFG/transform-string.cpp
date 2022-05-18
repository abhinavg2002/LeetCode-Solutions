// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void fun(string &a, map<char,int>&f){
        for(auto x:a){
            f[x-'a']++;
        }
    }
    int transform (string a, string b)
    {
        int n=a.size();
        map<char,int> f1, f2;
        fun(a, f1);
        fun(b, f2);
        if(f1!=f2)return -1;
        int i=n-1, j=n-1;
        int ct=0;
        while(i>=0){
            if(a[i]==b[j]){
                i--, j--;
            }else{
                while(i>=0 and a[i]!=b[j]){
                    i--;ct++;
                }
            }
        }
        return ct;
        //code here.
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends