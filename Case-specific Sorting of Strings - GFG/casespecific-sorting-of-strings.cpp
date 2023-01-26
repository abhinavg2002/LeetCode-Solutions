//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string a, b;
        for(auto x:str){
            if(isupper(x)){
                a+=x;
            }else{
                b+=x;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0, j=0, k=0;
        while(k<str.size()){
            if(isupper(str[k])){
                str[k++]=a[i++];
            }else{
                str[k++]=b[j++];
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends