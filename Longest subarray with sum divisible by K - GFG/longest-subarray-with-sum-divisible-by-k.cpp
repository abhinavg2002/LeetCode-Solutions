// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int a[], int n, int k)
	{
	    unordered_map<int, int> m;
        m[0]=-1;
        int s=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            s+=(x%k+k)%k;
            s%=k;
            if(m.count(s)){
                ans=max(ans, i-m[s]);
            }else{
                m[s]=i;
            }
        }
        return ans;
	    // Complete the function
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends