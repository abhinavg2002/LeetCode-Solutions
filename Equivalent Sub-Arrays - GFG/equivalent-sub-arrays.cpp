// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int fun(vector<int> &a, int b){
        int n=a.size();
        int i=0, j=0;
        // atmost b
        unordered_map<int,int> m;
        int ct=0;
        while(j<n){
            m[a[j]]++;
            while(m.size()>b){
                if(--m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            ct+=(j-i+1);
            j++;
        }
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n=a.size();
        return fun(a, k)-fun(a, k-1);
    }
    int countDistinctSubarray(int a[], int n)
    {
        //code here.
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            v.push_back(a[i]);
            m[a[i]]++;
        }
        return subarraysWithKDistinct(v, m.size());
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends