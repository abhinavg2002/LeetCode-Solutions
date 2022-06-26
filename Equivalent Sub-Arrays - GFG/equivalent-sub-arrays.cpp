// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int a[], int n)
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        int t=m.size();m.clear();
        
        int i=0, j=0, ct=0, ans=0;
        while(j<n){
            m[a[j]]++;
            if(m[a[j]]==1)ct++;
            while(ct==t){
                ans+=(n-j);
                m[a[i]]--;
                if(m[a[i]]==0)ct--;
                i++;
            }
            j++;
        }
        return ans;
        //code here.
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